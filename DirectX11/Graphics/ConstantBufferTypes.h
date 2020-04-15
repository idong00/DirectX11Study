#pragma once

#include <DirectXMath.h>

struct CB_VS_vertexshader
{
	DirectX::XMMATRIX mat;
};

struct CB_PS_light
{
	DirectX::XMFLOAT3 ambientLightColor; // 12 byte
	float ambientLightStrength;			 // 4 byte
};