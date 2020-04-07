#pragma once

#include <DirectXMath.h>

struct Vertex
{
	DirectX::XMFLOAT2 pos;

	Vertex() {}
	Vertex(float x, float y) :
		pos(x, y)
	{
	}
};