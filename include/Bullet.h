#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"


class Bullet
{
public:
	Bullet(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float startingRotation);
	Bullet(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float startingRotation, float _bulletSpeed);

	void process();

	sf::VertexArray objectVertexArr;
	GameObject gameObject;

private:
	void generateGeometry();
	void setBulletSpeed(sf::Vector2f startingVelocity, float startingRotation);

	float bulletSpeed = 100;
};