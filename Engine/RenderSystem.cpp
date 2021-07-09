#include "RenderSystem.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "ConstantBuffer.h"
#include "IndexBuffer.h"
#include <d3dcompiler.h>

RenderSystem::RenderSystem()
{
D3D_DRIVER_TYPE driver_types[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
};
UINT num_driver_types = ARRAYSIZE(driver_types);

D3D_FEATURE_LEVEL feature_levels[] =
{
	D3D_FEATURE_LEVEL_11_0
};
UINT num_feature_levels = ARRAYSIZE(feature_levels);

HRESULT res = 0;

for (UINT driver_type_index = 0; driver_type_index < num_driver_types;)
{
	res = D3D11CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels,
		num_feature_levels, D3D11_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_imm_context);
	if (SUCCEEDED(res))
		break;
	++driver_type_index;
}
if (FAILED(res))
{
	throw exception("Failed to create Render System");
}

m_imm_device_context = make_shared<DeviceContext>(m_imm_context, this);

m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device);
m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter);
m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);
}

SCPtr RenderSystem::createSwapChain(HWND hwnd, UINT width, UINT height)
{
	SCPtr sc = nullptr;

	try
	{
		sc= make_shared<SwapChain>(hwnd, width, height, this);
	}
	catch(...){}
	return sc;
}


DCPtr RenderSystem::getImmediateDeviceContext()
{
	return this->m_imm_device_context;
}

VBPtr RenderSystem::createVertexBuffer(void* list_vertices, UINT size_vertex, UINT size_list, void* shader_byte_code, size_t size_byte_shader)
{
	VBPtr vb = nullptr;

	try {
		vb = make_shared<VertexBuffer>(list_vertices, size_vertex, size_list, shader_byte_code, size_byte_shader, this);
	}
	catch (...) {}
	return vb;
}

CBptr RenderSystem::createConstBuffer(void* buffer, UINT size_buffer)
{
	CBptr cb = nullptr;
	try {
		cb = make_shared<ConstantBuffer>(buffer, size_buffer, this);
	}
	catch (...) {}
	return cb;
}

IBPtr RenderSystem::createIndexBuffer(void* list_indices, UINT size_list)
{
	IBPtr ib = nullptr;
	try {
		ib = make_shared<IndexBuffer>(list_indices, size_list, this);
	}
	catch(...){}
	return ib;
}

VSptr RenderSystem::createVertexShader(const void* shader_byte_code, size_t byte_code_size)
{
	VSptr vs = nullptr;
	try {
		vs = make_shared<VertexShader>(shader_byte_code, byte_code_size, this);
	}
	catch (...) {}
	return vs;

}
PSptr RenderSystem::createPixelShader(const void* shader_byte_code, size_t byte_code_size)
{
	PSptr ps = nullptr;
	try {
		ps = make_shared<PixelShader>(shader_byte_code, byte_code_size, this);
	}
	catch (...) {}
	return ps;
}

bool RenderSystem::compileVertexShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size)
{
	ID3DBlob* error_blob = nullptr;
	if (!SUCCEEDED(D3DCompileFromFile(file_name, nullptr, nullptr, entry_point_name, "vs_5_0", 0, 0, &m_blob, &error_blob)))
	{
		if (error_blob) error_blob->Release();
		return false;
	}

	*shader_byte_code = m_blob->GetBufferPointer();
	*byte_code_size = m_blob->GetBufferSize();

	return true;
}

bool RenderSystem::compilePixelShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size)
{
	ID3DBlob* error_blob = nullptr;
	if (!SUCCEEDED(D3DCompileFromFile(file_name, nullptr, nullptr, entry_point_name, "ps_5_0", 0, 0, &m_blob, &error_blob)))
	{
		if (error_blob) error_blob->Release();
		return false;
	}

	*shader_byte_code = m_blob->GetBufferPointer();
	*byte_code_size = m_blob->GetBufferSize();

	return true;
}

void RenderSystem::releaseCompiledShader()
{
	if (m_blob)m_blob->Release();
}

RenderSystem::~RenderSystem()
{
	if (m_vs)m_vs->Release();
	if (m_ps)m_ps->Release();

	if (m_vsblob)m_vsblob->Release();
	if (m_psblob)m_psblob->Release();

	m_dxgi_device->Release();
	m_dxgi_adapter->Release();
	m_dxgi_factory->Release();

	m_d3d_device->Release();
}