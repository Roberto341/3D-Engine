#pragma once
#include <memory>
using namespace std;
class SwapChain;
class DeviceContext;
class VertexBuffer;
class IndexBuffer;
class ConstantBuffer;
class VertexShader;
class PixelShader;
class RenderSystem;
class GraphicsEngine;
class Resource;
class ResourceManager;
class Texture;
class TextureManager;

typedef shared_ptr<SwapChain> SCPtr;
typedef shared_ptr<DeviceContext> DCPtr;
typedef shared_ptr<VertexBuffer> VBPtr;
typedef shared_ptr<IndexBuffer> IBPtr;
typedef shared_ptr<ConstantBuffer> CBptr;
typedef shared_ptr<VertexShader> VSptr;
typedef shared_ptr<PixelShader> PSptr;
typedef shared_ptr<Resource> RSptr;
typedef shared_ptr<Texture> TexturePtr;