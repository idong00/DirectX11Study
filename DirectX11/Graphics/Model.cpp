#include "Model.h"

bool Model::Initialize(ID3D11Device * device, ID3D11DeviceContext * deviceContext, ID3D11ShaderResourceView * texture, ConstantBuffer<CB_VS_vertexshader>& cb_vs_vertexshader)
{
	this->device = device;
	this->deviceContext = deviceContext;
	this->texture = texture;
	this->cb_vs_vertexshader = &cb_vs_vertexshader;

	try
	{
		//
		// textured square
		//
		Vertex v[] =
		{
			Vertex(-0.5f,  -0.5f,  -0.5f,  0.0f,  1.0f),   // Front Bottom Left  0
			Vertex(-0.5f,   0.5f,  -0.5f,  0.0f,  0.0f),   // Front Top Left     1
			Vertex( 0.5f,   0.5f,  -0.5f,  1.0f,  0.0f),   // Front Top Right    2
			Vertex( 0.5f,  -0.5f,  -0.5f,  1.0f,  1.0f),   // Front Bottom Right 3
			Vertex(-0.5f,  -0.5f,   0.5f,  0.0f,  1.0f),   // Back Bottom Left  0
			Vertex(-0.5f,   0.5f,   0.5f,  0.0f,  0.0f),   // Back Top Left     1
			Vertex( 0.5f,   0.5f,   0.5f,  1.0f,  0.0f),   // Back Top Right    2
			Vertex( 0.5f,  -0.5f,   0.5f,  1.0f,  1.0f),   // Back Bottom Right 3
		};

		// load vertex data
		HRESULT hr = this->vertexBuffer.Initialize(this->device, v, ARRAYSIZE(v));
		COM_ERROR_IF_FAILED(hr, "Failed to initialize vertex buffer.");

		DWORD indices[] =
		{
			0, 1, 2, //FRONT
			0, 2, 3, //FRONT
			4, 7, 6, //BACK 
			4, 6, 5, //BACK
			3, 2, 6, //RIGHT SIDE
			3, 6, 7, //RIGHT SIDE
			4, 5, 1, //LEFT SIDE
			4, 1, 0, //LEFT SIDE
			1, 5, 6, //TOP
			1, 6, 2, //TOP
			0, 3, 7, //BOTTOM
			0, 7, 4, //BOTTOM
		};

		// load index data
		hr = this->indexBuffer.Initialize(this->device, indices, ARRAYSIZE(indices));
		COM_ERROR_IF_FAILED(hr, "Failed to initialize index buffer.");
	}
	catch (COMException & exception)
	{
		ErrorLogger::Log(exception);
		return false;
	}

	this->UpdateWorldMatrix();
	return true;
}

void Model::SetTexture(ID3D11ShaderResourceView * texture)
{
	this->texture = texture;
}

void Model::Draw(const XMMATRIX & viewProjectionMatrix)
{
	//Update Constant buffer with WVP Matrix
	this->cb_vs_vertexshader->data.mat = this->worldMatrix * viewProjectionMatrix; //Calculate World-View-Projection Matrix
	this->cb_vs_vertexshader->data.mat = XMMatrixTranspose(this->cb_vs_vertexshader->data.mat);
	this->cb_vs_vertexshader->ApplyChanges();
	this->deviceContext->VSSetConstantBuffers(0, 1, this->cb_vs_vertexshader->GetAddressOf());

	this->deviceContext->PSSetShaderResources(0, 1, &this->texture); //Set Texture
	this->deviceContext->IASetIndexBuffer(this->indexBuffer.Get(), DXGI_FORMAT::DXGI_FORMAT_R32_UINT, 0);
	UINT offset = 0;
	this->deviceContext->IASetVertexBuffers(0, 1, this->vertexBuffer.GetAddressOf(), this->vertexBuffer.StridePtr(), &offset);
	this->deviceContext->DrawIndexed(this->indexBuffer.BufferSize(), 0, 0); //Draw
}

void Model::UpdateWorldMatrix()
{
	this->worldMatrix = XMMatrixIdentity();
}