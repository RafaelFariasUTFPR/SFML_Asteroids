#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <thread>

#include "SpaceShip.h"

class Game
{
public:
	Game();


	void beginPlay();
	void loop();



	sf::Clock globalClock;
	sf::Clock deltaTimeClock;
	

	sf::RenderWindow window;
	bool running = false;

	void physicsProcess();

protected:
	void preProcess();
	void process();
	float calculateDeltaTime();
	void draw();

	
	
	float deltaTime;
	float fps;
	SpaceShip spaceShip;
	


};

