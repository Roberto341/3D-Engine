#pragma once
#include <string>
using namespace std;
class Resource
{
public:
	Resource(const wchar_t* full_path);
	virtual ~Resource();
protected:
	wstring m_full_path;
};

