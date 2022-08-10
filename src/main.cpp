#include <SFML/Graphics.hpp>
#include "../include/Game.h"

#include <iostream>



int main()
{
	Game game1;
    game1.beginPlay();
	
	while (game1.window.isOpen())
	{
		game1.loop();

	}



	return 0;
}