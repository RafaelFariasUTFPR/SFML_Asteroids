#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "AsteroidMaster.h"

class Bullet
{
public:
	Bullet(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float startingRotation, float _bulletSpeed, std::vector<AsteroidMaster>& _asteroidArrPtr);
	Bullet(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float startingRotation, std::vector<AsteroidMaster>& _asteroidArrPtr);

	void process();

	sf::VertexArray objectVertexArr;
	GameObject gameObject;

	bool expired = false;
	

private:
	void generateGeometry();
	void setBulletSpeed(sf::Vector2f startingVelocity, float startingRotation);
	sf::Clock localClock;

	float lifeSpan = 1500;	//In milliseconds
	float bulletSpeed = 400;

	std::vector<AsteroidMaster>* asteroidArrPtr;
};