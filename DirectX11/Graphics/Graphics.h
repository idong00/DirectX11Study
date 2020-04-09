#pragma once

#include "AdapterReader.h"
#include "Shaders.h"
#include "Vertex.h"
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <WICTextureLoader.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBuffer.h"


class Graphics {
public:
	bool Initialize(HWND hWnd, int width, int height);
	void RenderFrame();

private:
	bool InitializeDirectX(HWND hWnd);
	bool InitializeShaders();
	bool InitializeScene();

private:
	// namespace : Microsoft::WRL
	// 스마트 포인터( ref 카운터 )
	Microsoft::WRL::ComPtr<ID3D11Device> device;  // 자원할당
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;  // 렌더 대상설정, 파이프라인에 넣고, GPU가 렌더링 명령 지시에 쓰임
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;  // 더블버퍼링 위해 필요
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

	VertexShader vertexshader;
	PixelShader pixelshader;
	ConstantBuffer<CB_VS_vertexshader> constantBuffer;

	VertexBuffer<Vertex> vertexBuffer;
	IndexBuffer indicesBuffer;

	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilState;

	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerState;

	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	std::unique_ptr<DirectX::SpriteFont> spriteFont;

	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> myTexture;

	int windowWidth = 0;
	int windowHeight = 0;
};