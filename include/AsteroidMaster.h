#pragma once

#include "GameObject.h"
#include "GlobalVariables.h"

class AsteroidMaster
{
public:
	AsteroidMaster();
	AsteroidMaster(int ySpawnPos, int spawnSide);
	AsteroidMaster(int xSpawnPos, int ySpawnPos, float size);

	void process();



	sf::VertexArray objectVertexArr;
	GameObject gameObject;


private:
	void generateGeometry();
	void setup();
	

	float offSet();

	float radius;
	float speed;



	//-1 == <-     1 == ->   
	int floatDirection = 1;
};

