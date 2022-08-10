#include <SFML/Graphics.hpp>
#include "../include/Game.h"

#include <iostream>

Game* game;

void physicsProcess()
{
	game->physicsProcess();
}

int main()
{
	Game game1;
	game = &game1;
    game1.beginPlay();
	std::thread physicsThread(physicsProcess);
	while (game1.window.isOpen())
	{
		game1.loop();
	}
	game1.running = false;

	physicsThread.join();


	return 0;
}