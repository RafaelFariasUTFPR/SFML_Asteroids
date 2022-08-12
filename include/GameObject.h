#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

#include "vertexOperations.h"
#include "RandomGenerator.h"
#include "GlobalVariables.h"

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
	void setWrapOffset(float xOffset, float yOffset) { wrapOffsetX = xOffset; wrapOffsetY = yOffset;};

	bool screenWrap = false;


	bool isOverlapping(sf::VertexArray targetVertexArr);
	std::vector <sf::VertexArray> collisionDebugLinesArr;
	sf::VertexArray collisionDebugLines;

private:
	void processWraping();

	sf::Vector2f speed;
	double rotationSpeed;


	bool drawCollisionDebugLines = true;
	float collisionDetectionDist = 200;
	float wrapOffsetX = 0;
	float wrapOffsetY = 0;

	

	

};

