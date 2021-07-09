#include "AppWindow.h"
#include "InputSystem.h"
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	try {
		GraphicsEngine::create();
		InputSystem::create();
	}
	catch (...) { return -1; }
	{
		try 
		{
			AppWindow app;
			while (app.isRun());
		}
		catch (...) {
			InputSystem::release();
			GraphicsEngine::release();
			return -1;
		}
	}
	InputSystem::release();
	GraphicsEngine::release();
	return 0;
}