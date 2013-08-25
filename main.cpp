#include <stdlib.h>
#include <stdio.h>
#include "Game.h"

int main ( int argc, char** argv )
{
	Game	game;

	if (game.Init())
	{
		game.Run();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
