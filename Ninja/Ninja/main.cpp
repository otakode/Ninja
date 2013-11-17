#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "../../Engine/Engine/Game.h"
#include "TestLevel.h"

/*int main()
{
	Game::Run();

	return 0;
}*/

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game game;

	TestLevel level;
	Game::LoadLevel(&level);
	game.Run();
	level.UnLoad();

	return EXIT_SUCCESS;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
	}

	return 0;
}