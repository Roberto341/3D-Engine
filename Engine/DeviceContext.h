#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include <exception>
class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* device_context, RenderSystem* system);
	void clearRenderTargetColor(SCPtr swap_chain,float red, float green, float blue, float alpha);
	void setVertexBuffer(VBPtr vertex_buffer);
	void setIndexBuffer(IBPtr index_buffer);
	void drawTriangleList(UINT vertex_count, UINT start_vertex_index);
	void drawIndexedTriangleList(UINT index_count, UINT start_vertex_count, UINT start_index_location);
	void drawTriangleStrip(UINT vertex_count, UINT start_vertex_index);
	void setViewportSize(UINT width, UINT height);
	void setVertexShader(VSptr vertexShader);
	void setPixelShader(PSptr pixleShader);

	void setConstBuffer(VSptr vertex_shader, CBptr buffer);
	void setConstBuffer(PSptr pixel_shader, CBptr buffer);

	~DeviceContext();
private:
	ID3D11DeviceContext * m_device_context;
	RenderSystem* m_system = nullptr;
	friend class ConstantBuffer;
};

