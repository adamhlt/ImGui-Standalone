#include "pch.h"
#include "ui/Window.h"

#ifndef _WINDLL

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    Window::Run();

    return 0;
}

#endif
