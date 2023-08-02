#include "UI.h"

#ifdef _WINDLL

HANDLE hCurrentUIThread = nullptr;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);
        UI::hCurrentModule = hinstDLL;
        hCurrentUIThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)UI::Render, nullptr, NULL, nullptr);
    }

    if (fdwReason == DLL_PROCESS_DETACH)
    {
        TerminateThread(hCurrentUIThread, 0);
        CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)FreeLibrary, hinstDLL, NULL, nullptr);
    }

    return TRUE;
}

#else

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    UI::Render();

    return 0;
}

#endif