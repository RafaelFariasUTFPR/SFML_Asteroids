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
	Game();


	void beginPlay();
	void loop();


	sf::RenderWindow window;


	

private:
	//Game loop functions
	void preProcess();
	void input();
	void process();
	void draw();
	
	void endPlay();
	
	float calculateDeltaTime();

	void spawnAsteroid();

	sf::Clock globalClock;
	sf::Clock deltaTimeClock;

	double deltaTime;
	float fps;
	SpaceShip player1;
	sf::Font arialFont;
	sf::Text fpsText;
	

	
	std::vector <AsteroidMaster> asteroidArr;
};


