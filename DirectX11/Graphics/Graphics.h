#pragma once

#include "AdapterReader.h"
#include "Shaders.h"
#include "Vertex.h"

class Graphics {
public:
	bool Initialize(HWND hWnd, int width, int height);
	void RenderFrame();

private:
	bool InitializeDirectX(HWND hWnd, int width, int height);
	bool InitializeShaders();
	bool InitializeScene();

private:
	// 스마트 포인터( ref 카운터 )
	Microsoft::WRL::ComPtr<ID3D11Device> device;  // 자원할당
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;  // 렌더 대상설정, 파이프라인에 넣고, GPU가 렌더링 명령 지시에 쓰임
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;  // 더블버퍼링 위해 필요
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

	VertexShader vertexshader;
	PixelShader pixelshader;

	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerState;;
};