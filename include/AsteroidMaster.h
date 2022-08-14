#pragma once

#include "GameObject.h"
#include "GlobalVariables.h"

class AsteroidMaster
{
public:
	AsteroidMaster();
	AsteroidMaster(int ySpawnPos, int spawnSide);
	AsteroidMaster(int ySpawnPos, int spawnSide, int _size);
	AsteroidMaster(sf::Vector2f spawnPos, int _size, int _floatDirection);

	void process();
	void destroyed();


	sf::VertexArray objectVertexArr;
	GameObject gameObject;

	bool expired = false;

	int size = 3;
	float radius;

	//-1 == <-     1 == ->   
	int floatDirection = 1;
private:
	void generateGeometry();
	void setup();
	

	float offSet();

	
	float speed;




};

