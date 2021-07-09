#include "VertexShader.h"
#include "RenderSystem.h"

VertexShader::VertexShader(const void* shader_byte_code, size_t byte_code_size, RenderSystem* system):m_system(system)
{
	if (!SUCCEEDED(m_system->m_d3d_device->CreateVertexShader(shader_byte_code, byte_code_size, nullptr, &m_vs)))
	{
		throw exception("Vertex shader was not created");
	}
}
VertexShader::~VertexShader() 
{
	m_vs->Release();
}