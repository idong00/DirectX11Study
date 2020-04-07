#pragma once
#include "RenderWindow.h"
#include "Keyboard/KeyboardClass.h"

class WindowContainer {
public:
	LRESULT WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	RenderWindow render_window;
	KeyboardClass keyboard;

private:

};
