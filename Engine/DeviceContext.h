#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include <exception>
class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* device_context, RenderSystem* system);
	void clearRenderTargetColor(const SCPtr& swap_chain,float red, float green, float blue, float alpha);
	void setVertexBuffer(const VBPtr& vertex_buffer);
	void setIndexBuffer(const IBPtr& index_buffer);

	void drawTriangleList(UINT vertex_count, UINT start_vertex_index);
	void drawIndexedTriangleList(UINT index_count, UINT start_vertex_count, UINT start_index_location);
	void drawTriangleStrip(UINT vertex_count, UINT start_vertex_index);
	void setViewportSize(UINT width, UINT height);

	void setVertexShader(const VSptr& vertexShader);
	void setPixelShader(const PSptr& pixleShader);

	void setTexture(const VSptr& vertex_shader, const TexturePtr& texture);
	void setTexture(const PSptr& pixel_shader,  const TexturePtr& texture);


	void setConstBuffer(const VSptr& vertex_shader, const CBptr& buffer);
	void setConstBuffer(const PSptr& pixel_shader, const CBptr& buffer);

	~DeviceContext();
private:
	ID3D11DeviceContext * m_device_context;
	RenderSystem* m_system = nullptr;
	friend class ConstantBuffer;
};

