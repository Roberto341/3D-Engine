#pragma once
#include <unordered_map>
#include <string>
#include "Prerequisites.h"
using namespace std;
class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	RSptr createResourceFromFile(const wchar_t* file_path);
protected:
	virtual Resource* createResourceFromFileConcrete(const wchar_t* file_path) = 0;
private:
	std::unordered_map<wstring, RSptr> m_map_resources;
};

