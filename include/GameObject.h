#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "vertexOperations.h"
#include "RandomGenerator.h"

class GameObject
{
public:
	GameObject();

	void process();



	sf::VertexArray vertexArr;
	
	
	sf::Vector2f position;
	float rotation;
	float rotationRadians = 0;

	
	sf::Vector2f getSpeed() { return speed; }
	double getRotationSpeed() { return rotationSpeed; }
	float getWrapOffsetX() { return wrapOffsetX; }
	float getWrapOffsetY() { return wrapOffsetY; }

	void setPosition(sf::Vector2f newPosition);
	void setRotation(double newRotation);
	void setSpeed(sf::Vector2f newSpeed) { speed = newSpeed; }
	void setRotationSpeed(double newRotationSpeed) { rotationSpeed = newRotationSpeed; }
	void setDeltaTime(double newDeltaTime) { deltaTime = newDeltaTime; }
	void setScreenSizeX(int newSize) { screenSizeX = newSize; }
	void setScreenSizeY(int newSize) { screenSizeY = newSize; }
	void setWrapOffset(float xOffset, float yOffset) { wrapOffsetX = xOffset; wrapOffsetY = yOffset;};

	bool screenWrap = false;



private:
	void processWraping();

	sf::Vector2f speed;
	double rotationSpeed;

	double deltaTime;

	int screenSizeX;
	int screenSizeY;

	float wrapOffsetX = 0;
	float wrapOffsetY = 0;

	

	

};

