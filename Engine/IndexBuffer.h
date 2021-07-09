#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include <exception>
using namespace std;
class IndexBuffer
{
public:
	IndexBuffer(void* list_indices, UINT size_list, RenderSystem* system);
	UINT getSizeIndexList();
	~IndexBuffer();
private:
	UINT m_size_list;
private:
	ID3D11Buffer* m_buffer;
	RenderSystem* m_system = nullptr;
private:
	friend class DeviceContext;
};

