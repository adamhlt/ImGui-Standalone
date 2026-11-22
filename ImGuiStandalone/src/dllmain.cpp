#include "pch.h"
#include "ui/Window.h"

#ifdef _WINDLL

static HANDLE hCurrentUIThread = nullptr;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);
        Window::hCurrentModule = hinstDLL;
        hCurrentUIThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Window::Run, nullptr, NULL, nullptr);
    }

    if (fdwReason == DLL_PROCESS_DETACH)
        TerminateThread(hCurrentUIThread, 0);

    return TRUE;
}

#endif
