#pragma once

#include <DirectXMath.h>

struct Vertex
{
	DirectX::XMFLOAT2 pos;
	DirectX::XMFLOAT3 color;

	Vertex() {}
	Vertex(float x, float y, float r, float g, float b) :
		pos(x, y),
		color(r, g, b)
	{
	}
};