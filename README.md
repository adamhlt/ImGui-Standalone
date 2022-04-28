![Banner](https://raw.githubusercontent.com/adamhlt/ImGui-Standalone/main/Ressources/banner.png?token=GHSAT0AAAAAABT6O75K4ZK35V554OA5G3UQYTLAKJA)

# ImGui Standalone

[![C++](https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/C%2B%2B) [![Windows](https://img.shields.io/badge/platform-Windows-0078d7.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/Microsoft_Windows) [![x86](https://img.shields.io/badge/arch-x86-red.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/X86) [![x64](https://img.shields.io/badge/arch-x64-green.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/X64)

## :open_book: Project Overview :

ImGui Standalone use D3D11 to create GUI application with ImGui or for games that does not use DirectX and games which ImGui block the render.

You can easily use it as a DLL for external in an internal cheat or build GUI application with ImGui. Everything is setup you just need to choose between DLL or EXE. ImGui Standalone create his own window, if you use it as a DLL you main process don't need to use DirectX.

This project works in x86 and x64, DLL and EXE.

#### Used librairies :

- [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812)
- [ImGui](https://github.com/ocornut/imgui)

## :rocket: Getting Started

Make that **DXSDK_DIR** is declared in your environment variables.

To see your environment variables :

> **Settings --> System --> About --> System Advanced Settings --> Environment Variables**

### Visual Studio :

1. Open the solution file (.sln).
2. Build the project in Release (x86 or x64)

Every configuration in x86 / x64 (Debug and Realese) are already configured with librairies and includes.

Everything is setup, you just need to choose between DLL or EXE.

⚠️ If you have any linking error when compiling make sure that you have correctly install DirectX SDK.

## 🧪 Demonstration :
