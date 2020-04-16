#pragma once

#include <DirectXMath.h>

struct CB_VS_vertexshader
{
	DirectX::XMMATRIX wvpMatrix;
	DirectX::XMMATRIX worldMatrix;
};

struct CB_VS_vertexshader_2d
{
	DirectX::XMMATRIX wvpMatrix;
};

struct CB_PS_light
{
	DirectX::XMFLOAT3 ambientLightColor; // 12 byte
	float ambientLightStrength;			 // 4 byte

	DirectX::XMFLOAT3 dynamicLightColor; // 12 byte
	float dynamicLightStrength;			 // 4 byte
	DirectX::XMFLOAT3 dynamicLightPosition; // 12 byte
	float dynamicLightAttenuation_a;
	float dynamicLightAttenuation_b;
	float dynamicLightAttenuation_c;
};