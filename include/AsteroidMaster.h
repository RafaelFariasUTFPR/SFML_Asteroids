#pragma once

#include "GameObject.h"

class AsteroidMaster
{
public:
	AsteroidMaster();
	AsteroidMaster(int xSpawnPos, int ySpawnPos);
	AsteroidMaster(int xSpawnPos, int ySpawnPos, float size);

	//void spawn(int ySpawnPos, int side);


	sf::VertexArray objectVertexArr;
	GameObject gameObject;


private:
	void generateGeometry(float asteroidSize);

};

