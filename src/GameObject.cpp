#include "../include/GameObject.h"

GameObject::GameObject()
{
	position = sf::Vector2f(0, 0);
	rotation = 0;
	speed = sf::Vector2f(0, 0);
	rotationSpeed = 0;
}

void GameObject::process()
{
	setRotation(rotation + (getRotationSpeed() * global::deltaTime));

	setPosition(position + sf::Vector2f((getSpeed().x * global::deltaTime), (getSpeed().y * global::deltaTime)));
	
	
	if (screenWrap)
		processWraping();
}

void GameObject::processWraping()
{
	if (position.x - wrapOffsetX > global::screenWidth)
		setPosition(sf::Vector2f(- wrapOffsetX, position.y));
	if (position.x + wrapOffsetX < 0)
		setPosition(sf::Vector2f(global::screenWidth + wrapOffsetX, position.y));

	if (position.y - wrapOffsetY > global::screenHeight)
		setPosition(sf::Vector2f(position.x, -wrapOffsetY));
	if (position.y + wrapOffsetY < 0)
		setPosition(sf::Vector2f(position.x, global::screenHeight + wrapOffsetY));

}


void GameObject::setPosition(sf::Vector2f newPosition)
{
	for (int i = 0; i < vertexArr.getVertexCount(); i++)
	{
		sf::Vector2f tempVector2;
		tempVector2 = vertexArr[i].position + (newPosition - position);
		vertexArr[i].position = tempVector2;
	}
	position = newPosition;
	
}

void GameObject::setRotation(double newRotation)
{
	//Mantendo rotação menor que 360°
	if (newRotation > 360)
		newRotation = remainder(newRotation, 360);

	sf::VertexArray tempVertexArr;
	for (int i = 0; i < vertexArr.getVertexCount(); i++)
	{
		sf::Vector2f tempVector2;
		tempVector2 = rotatePointArrounPoint(vertexArr[i].position, position , (rotation - newRotation));
		//sf::Vector2f center(vertexArr[i].position - position);
		//Definindo o centro
		vertexArr[i].position = tempVector2;
		

	}
	rotation = newRotation;
	rotationRadians = deg2rad(rotation);
}
