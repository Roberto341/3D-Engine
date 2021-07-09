#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
using namespace std;
class ConstantBuffer
{
public:
	ConstantBuffer(void* buffer, UINT size_buffer, RenderSystem* system);
	void update(DCPtr context, void* buffer);
	~ConstantBuffer();
private:
	ID3D11Buffer* m_buffer;
	RenderSystem* m_system = nullptr;
	friend class DeviceContext;
};

