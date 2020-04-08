#pragma once

#include "AdapterReader.h"
#include "Shaders.h"
#include "Vertex.h"
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <WICTextureLoader.h>
#include "VertexBuffer.h"

class Graphics {
public:
	bool Initialize(HWND hWnd, int width, int height);
	void RenderFrame();

private:
	bool InitializeDirectX(HWND hWnd, int width, int height);
	bool InitializeShaders();
	bool InitializeScene();

private:
	// namespace : Microsoft::WRL
	// ����Ʈ ������( ref ī���� )
	Microsoft::WRL::ComPtr<ID3D11Device> device;  // �ڿ��Ҵ�
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;  // ���� �����, ���������ο� �ְ�, GPU�� ������ ��� ���ÿ� ����
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;  // ������۸� ���� �ʿ�
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

	VertexShader vertexshader;
	PixelShader pixelshader;

	VertexBuffer<Vertex> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indicesBuffer;

	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilState;

	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerState;

	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	std::unique_ptr<DirectX::SpriteFont> spriteFont;

	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> myTexture;
};