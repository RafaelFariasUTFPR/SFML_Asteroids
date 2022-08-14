#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "SpaceShip.h"
#include "AsteroidMaster.h"
#include "RandomGenerator.h"
#include "GlobalVariables.h"


class Game
{
public:
	Game(sf::RenderWindow &_window);


	void beginPlay();
	void loop();


	sf::RenderWindow *window;

	bool running = true;

	bool restart = false;
	


private:
	//Game loop functions
	void preProcess();
	void input();
	void process();
	void draw();
	
	void endPlay();
	
	float calculateDeltaTime();

	void spawnAsteroid(int asteroidSize);
	void splitAsteroid(sf::Vector2f position, sf::Vector2f velocity, int parentSize, int floatDirection);

	sf::Clock globalClock;
	sf::Clock deltaTimeClock;

	double deltaTime;
	float fps;
	SpaceShip player1;
	sf::Font arialFont;
	sf::Text fpsText;
	

	
	std::vector <AsteroidMaster> asteroidArr;
};


