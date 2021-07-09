#pragma once
#include "ResourceManager.h"
class TextureManager: public ResourceManager
{
public:
	TextureManager();
	~TextureManager();
	RSptr createResourceFromFile(const wchar_t* file_path);
};

