#include "pch.h"
#include "ui/Window.h"
#include "ui/Renderer.h"
#include "ui/Menu.h"

HMODULE Window::hCurrentModule = nullptr;

#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E0 // From Windows SDK 8.1+ headers
#endif

LRESULT WINAPI Window::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (Renderer::IsReady() && wParam != SIZE_MINIMIZED)
            Renderer::Resize((UINT)LOWORD(lParam), (UINT)HIWORD(lParam));
        return 0;

    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;

    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;

    case WM_DPICHANGED:
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)
        {
            const RECT* suggested_rect = (RECT*)lParam;
            ::SetWindowPos(hWnd, nullptr, suggested_rect->left, suggested_rect->top, suggested_rect->right - suggested_rect->left, suggested_rect->bottom - suggested_rect->top, SWP_NOZORDER | SWP_NOACTIVATE);
        }
        break;

    default:
        break;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

void Window::Run()
{
    ImGui_ImplWin32_EnableDpiAwareness();
    const WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, _T("ImGui Standalone"), nullptr };
    ::RegisterClassEx(&wc);
    const HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("ImGui Standalone"), WS_OVERLAPPEDWINDOW, 100, 100, 50, 50, NULL, NULL, wc.hInstance, NULL);

    if (!Renderer::CreateDevice(hwnd))
    {
        Renderer::Cleanup();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return;
    }

    ::ShowWindow(hwnd, SW_HIDE);
    ::UpdateWindow(hwnd);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 4.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    const HMONITOR monitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFO info = {};
    info.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(monitor, &info);
    const int monitor_height = info.rcMonitor.bottom - info.rcMonitor.top;

    if (monitor_height > 1080)
    {
        const float fScale = 2.0f;
        ImFontConfig cfg;
        cfg.SizePixels = 13 * fScale;
        ImGui::GetIO().Fonts->AddFontDefault(&cfg);
    }

    ImGui::GetIO().IniFilename = nullptr;

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(Renderer::GetDevice(), Renderer::GetDeviceContext());

    const ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    bool bDone = false;

    while (!bDone)
    {
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                bDone = true;
        }

        if (GetAsyncKeyState(VK_END) & 1)
            bDone = true;

        if (bDone)
            break;

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            Menu::Draw();
        }
        ImGui::EndFrame();

        Renderer::RenderFrame(clear_color);

        #ifndef _WINDLL
            if (!Menu::isActive())
                break;
        #endif
    }

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    Renderer::Cleanup();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    #ifdef _WINDLL
    CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)FreeLibrary, hCurrentModule, NULL, nullptr);
    #endif
}
