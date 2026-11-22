<div align="center">

# ImGui Standalone

**D3D11 ImGui external menu, as an EXE or a DLL (x86 / x64)**

![C++](https://img.shields.io/badge/language-C%2B%2B-16171C?style=flat-square)
![Windows](https://img.shields.io/badge/platform-Windows-16171C?style=flat-square)
![x86 | x64](https://img.shields.io/badge/arch-x86%20%7C%20x64-16171C?style=flat-square)
[![License](https://img.shields.io/badge/license-GPLv3-16171C?style=flat-square)](LICENSE)

</div>

---

ImGui Standalone uses D3D11 to create a GUI application with ImGui. It also works for games that do not use DirectX or that block ImGui rendering.

It creates its own window, so as a DLL the host process does not need to use DirectX. Everything is set up: you only choose between EXE and DLL.

Looking for a DirectX overlay instead? See [D3D9 Overlay ImGui](https://github.com/adamhlt/D3D9-Overlay-ImGui) and [D3D11 Overlay ImGui](https://github.com/adamhlt/D3D11-Overlay-ImGui).

### GUI Application (EXE - x64)
https://user-images.githubusercontent.com/48086737/165841805-e6bfc190-eaa4-4f0e-8e82-9b9f33bad249.mp4

### Notepad Injection (DLL - x64)
https://user-images.githubusercontent.com/48086737/165843014-4a19ac67-ac33-4c47-acde-fa26b7b7e14d.mp4

## Features

**Targets**
- x86 and x64, Debug and Release
- EXE or DLL from the same code base
- Own Win32 window and D3D11 device, no dependency on the host process

**DLL mode**
- `Insert` shows or hides the menu
- `End` closes the menu and unloads the DLL

**Customize**
- Write your interface in `Menu::Draw` (`ImGuiStandalone/src/ui/Menu.cpp`)
- ImGui sources are kept untouched in `vendor/imgui/`

## Usage

Add your widgets in `Menu::Draw`:

```cpp
void Menu::Draw()
{
	if (isActive())
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			ImGui::Text("Create your own menu.");
		}
		ImGui::End();
	}
}
```

The project layout:

```
ImGuiStandalone.sln
ImGuiStandalone/
	src/
		main.cpp         EXE entry point (wWinMain)
		dllmain.cpp      DLL entry point (DllMain)
		pch.h / pch.cpp  precompiled header
		ui/
			Window.*     Win32 window, message loop, ImGui setup
			Renderer.*   D3D11 device, swap chain, render target
			Menu.*       your ImGui menu
vendor/imgui/            ImGui sources
```

## Build

1. Install the [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812).
2. Make sure `DXSDK_DIR` is declared in your environment variables (**Settings > System > About > Advanced system settings > Environment Variables**).
3. Open `ImGuiStandalone.sln` in Visual Studio.
4. Build in Release (x86 or x64).

- **Output:** every configuration is already set up with libraries and includes
- **Linking error:** check that the DirectX SDK is correctly installed and `DXSDK_DIR` is set

## License

This project is licensed under the [GNU GPLv3](LICENSE).
