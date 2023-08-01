```
            ____          ______      _    _____ __                  __      __          
           /  _/___ ___  / ____/_  __(_)  / ___// /_____ _____  ____/ /___ _/ /___  ____  ___
           / // __ `__ \/ / __/ / / / /   \__ \/ __/ __ `/ __ \/ __  / __ `/ / __ \/ __ \/ _ \
         _/ // / / / / / /_/ / /_/ / /   ___/ / /_/ /_/ / / / / /_/ / /_/ / / /_/ / / / /  __/
        /___/_/ /_/ /_/\____/\__,_/_/   /____/\__/\__,_/_/ /_/\__,_/\__,_/_/\____/_/ /_/\___/
                                                                                     
                                                                                   
                                   D3D11 ImGui External (x86 / x64)
                                    EXE / DLL ImGui External Menu
```
<p align="center">
    <img src="https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=for-the-badge&logo=appveyor" alt="C++">
    <img src="https://img.shields.io/badge/platform-Windows-0078d7.svg?style=for-the-badge&logo=appveyor" alt="Windows">
    <img src="https://img.shields.io/badge/arch-x86-red.svg?style=for-the-badge&logo=appveyor" alt="x86">
    <img src="https://img.shields.io/badge/arch-x64-green.svg?style=for-the-badge&logo=appveyor" alt="x64">
</p>

## :open_book: Project Overview :

ImGui Standalone use D3D11 to create GUI application with ImGui or for games that does not use DirectX and games which ImGui block the render.

You can easily use it as a DLL for external in an internal cheat or build GUI application with ImGui. Everything is setup you just need to choose between DLL or EXE. ImGui Standalone create his own window, if you use it as a DLL you main process don't need to use DirectX.

This project works in x86 and x64, DLL and EXE.

#### Used librairies :

- [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812)
- [ImGui](https://github.com/ocornut/imgui)

## :rocket: Getting Started

> **Note** <br>
> Make sure that **DXSDK_DIR** is declared in your environment variables.

To see your environment variables :

> **Settings --> System --> About --> System Advanced Settings --> Environment Variables**

### Visual Studio :

1. Open the solution file (.sln).
2. Build the project in Release (x86 or x64)

Every configuration in x86 / x64 (Debug and Realese) are already configured with librairies and includes.

Everything is setup, you just need to choose between DLL or EXE.

> **Warning** <br>
> If you have any linking error when compiling make sure that you have correctly install DirectX SDK.

## 🧪 Demonstration :

### GUI Application (EXE - x64)
https://user-images.githubusercontent.com/48086737/165841805-e6bfc190-eaa4-4f0e-8e82-9b9f33bad249.mp4

### Notepad Injection (DLL - x64)
The insert key is used to hide/show the menu.

https://user-images.githubusercontent.com/48086737/165843014-4a19ac67-ac33-4c47-acde-fa26b7b7e14d.mp4
