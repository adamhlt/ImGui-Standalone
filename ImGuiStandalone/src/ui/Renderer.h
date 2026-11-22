#ifndef RENDERER_H
#define RENDERER_H

#include "pch.h"

class Renderer
{
private:
	static ID3D11Device* pd3dDevice;
	static ID3D11DeviceContext* pd3dDeviceContext;
	static IDXGISwapChain* pSwapChain;
	static ID3D11RenderTargetView* pMainRenderTargetView;

	static void CreateRenderTarget();
	static void CleanupRenderTarget();

public:
	static bool CreateDevice(HWND hWnd);
	static void Cleanup();
	static void Resize(UINT width, UINT height);
	static bool IsReady();

	static ID3D11Device* GetDevice();
	static ID3D11DeviceContext* GetDeviceContext();

	// Clears the back buffer, draws the current ImGui draw data and presents it.
	static void RenderFrame(const ImVec4& clearColor);
};

#endif
