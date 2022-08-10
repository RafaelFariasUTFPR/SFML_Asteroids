#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "SpaceShip.h"
#include "AsteroidMaster.h"


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


	std::random_device randomSeed; // obtain a random number from hardware
	std::mt19937 randomGenerator; // seed the generator

	double deltaTime;
	float fps;
	SpaceShip player1;
	sf::Font arialFont;
	sf::Text fpsText;
	
	int screenSizeX = 800;
	int screenSizeY = 800;

	
	std::vector <AsteroidMaster> asteroidArr;
};


