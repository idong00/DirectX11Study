#pragma once

#include <DirectXMath.h>

struct Vertex
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT3 color;

	Vertex() {}
	Vertex(float x, float y, float z, float r, float g, float b) :
		pos(x, y, z),
		color(r, g, b)
	{
	}
};