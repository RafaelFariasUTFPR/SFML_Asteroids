#include "../include/GameObject.h"

GameObject::GameObject()
{
	position = sf::Vector2f(0, 0);
	rotation = 0;
	speed = sf::Vector2f(0, 0);
	rotationSpeed = 0;


	collisionDebugLines.setPrimitiveType(sf::Lines);


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

bool GameObject::isOverlapping(sf::VertexArray targetVertexArr, sf::Vector2f targetPosition)
{
	collisionDebugLines.clear();

	int targetArrVertexCount = targetVertexArr.getVertexCount();
	bool isInside = false;
	for (int i = 0; i < vertexArr.getVertexCount(); i++)
	{
		sf::Vector2f initialPoint(vertexArr[i].position);
		sf::Vector2f endPoint(targetPosition);

		//Apenas realizará os calculos caso o alvo esteja dentro da collisionDetectionDist
		if (sqrt(pow((initialPoint.x - endPoint.x), 2) + pow((initialPoint.y - endPoint.y), 2)) > collisionDetectionDist)
			continue;

		if (drawCollisionDebugLines)
		{
			collisionDebugLines.append(sf::Vertex(initialPoint, sf::Color::Red));
			collisionDebugLines.append(sf::Vertex(endPoint, sf::Color::Red));
		}

		bool intersectedLines = false;
		for (int j = 1; j < targetArrVertexCount; j++)
		{
			
			sf::Vector2f initialLinePoint(targetVertexArr[j-1].position);
			sf::Vector2f endLinePoint(targetVertexArr[j].position);
			
			

			if (doLinesIntersect(initialPoint, endPoint, initialLinePoint, endLinePoint))
			{
				if (drawCollisionDebugLines)
				{
					collisionDebugLines.append(sf::Vertex(initialLinePoint, sf::Color::Blue));
					collisionDebugLines.append(sf::Vertex(endLinePoint, sf::Color::Blue));

					collisionDebugLinesArr.push_back(collisionDebugLines);
				}
				intersectedLines = true;
				
			}

		}

		if (!intersectedLines)
			return true;

	}
	
	return false;
}