#pragma once

#include "AdapterReader.h"

class Graphics {
public:
	bool Initialize(HWND hWnd, int width, int height);

private:
	bool InitializeDirectX(HWND hWnd, int width, int height);

private:
	// ����Ʈ ������( ref ī���� )
	Microsoft::WRL::ComPtr<ID3D11Device> device;  // �ڿ��Ҵ�
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;  // ���� �����, ���������ο� �ְ�, GPU�� ������ ��� ���ÿ� ����
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;  // ������۸� ���� �ʿ�
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;
};