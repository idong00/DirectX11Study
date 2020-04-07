#include "Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Engine engine;
	engine.Initialize(hInstance, "KDH", "MyWindowClass", 800, 600);

	while (engine.ProcessMessages())
	{
		engine.Update();
		engine.RenderFrame();
	}
	return 0;
}

// input assembler
// vertex shader
// rasterizer
// pixel shader
// output merger