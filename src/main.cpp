#include <SFML/Graphics.hpp>



#include "../include/Game.h"
#include "GlobalVariables.h"

#include <iostream>


int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8.0;
	sf::RenderWindow window(sf::VideoMode(global::screenHeight, global::screenWidth), "Asteroids", sf::Style::Close, settings);
	
	Game game1(window);

	game1.beginPlay();
	while (game1.running)
	{
		game1.loop();
	}



	return 0;
}
