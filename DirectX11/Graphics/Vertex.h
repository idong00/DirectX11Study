#pragma once

#include <DirectXMath.h>

struct Vertex2D
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;

	Vertex2D() {}
	Vertex2D(float x, float y, float z, float u, float v) :
		pos(x, y, z),
		texCoord(u, v)
	{
	}
};

struct Vertex3D
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
	DirectX::XMFLOAT3 normal;

	Vertex3D() {}
	Vertex3D(float x, float y, float z, float u, float v, float nx, float ny, float nz) :
		pos(x, y, z),
		texCoord(u, v),
		normal(nx, ny, nz)
	{
	}
};