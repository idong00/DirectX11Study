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
	// ����Ʈ ������( ref ī���� )
	Microsoft::WRL::ComPtr<ID3D11Device> device;  // �ڿ��Ҵ�
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;  // ���� �����, ���������ο� �ְ�, GPU�� ������ ��� ���ÿ� ����
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;  // ������۸� ���� �ʿ�
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

	VertexShader vertexshader;
	PixelShader pixelshader;

	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerState;;
};