#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

#include "SpaceShip.h"

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


	sf::Clock globalClock;
	sf::Clock deltaTimeClock;




	double deltaTime;
	float fps;
	SpaceShip player1;
	sf::Font arialFont;
	sf::Text fpsText;
	
	int screenSizeX = 800;
	int screenSizeY = 800;

};


