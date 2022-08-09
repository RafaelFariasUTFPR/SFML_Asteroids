#include "../include/GameObject.h"

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

void GameObject::setRotation(float newRotation)
{

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
}
