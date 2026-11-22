#include "pch.h"
#include "ui/Menu.h"

LPCSTR Menu::lpWindowName = "ImGui Standalone";
ImVec2 Menu::vWindowSize = { 350, 75 };
ImGuiWindowFlags Menu::WindowFlags = 0;
bool Menu::bDraw = true;

void Menu::Active()
{
	bDraw = true;
}

bool Menu::isActive()
{
	return bDraw == true;
}

void Menu::Draw()
{
	if (isActive())
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{

			ImGui::Text("Create your own menu.");

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		}
		ImGui::End();
	}

	#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
	#endif
}
