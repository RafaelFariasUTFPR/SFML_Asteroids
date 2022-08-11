#pragma once

#include "GameObject.h"

class AsteroidMaster
{
public:
	AsteroidMaster();
	AsteroidMaster(int ySpawnPos, int spawnSide);
	AsteroidMaster(int xSpawnPos, int ySpawnPos, float size);

	void process(double _deltaTime);

	void setScreenSizeX(int newSize) { screenSizeX = newSize; gameObject.setScreenSizeX(newSize); }
	void setScreenSizeY(int newSize) { screenSizeY = newSize; gameObject.setScreenSizeY(newSize); }


	sf::VertexArray objectVertexArr;
	GameObject gameObject;


private:
	void generateGeometry();
	void setup();
	

	float offSet();

	float radius;
	float speed;

	int screenSizeX;
	int screenSizeY;

	//-1 == <-     1 == ->   
	int floatDirection = 1;
};

