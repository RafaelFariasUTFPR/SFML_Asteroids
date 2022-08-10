#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "vertexOperations.h"
#include "RandomGenerator.h"

class GameObject
{
public:
	GameObject();


	void setPosition(sf::Vector2f newPosition);
	void setRotation(double newRotation);

	

	sf::VertexArray vertexArr;
	
	
	sf::Vector2f position;
	float rotation;
	float rotationRadians = 0;


	



protected:


};

