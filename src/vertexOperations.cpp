#include "../include/vertexOperations.h"


sf::Vector2f rotatePointArrounPoint(sf::Vector2f myPoint, sf::Vector2f centerPoint, float rotationAngle)
{
	// Convertendo de graus para radianos e invertendo o sentido de rotação
	rotationAngle = (-rotationAngle) * (PI / 180);

	float s = sin(rotationAngle);
	float c = cos(rotationAngle);

	// Retornando o ponto para 0,0
	myPoint.x -= centerPoint.x;
	myPoint.y -= centerPoint.y;

	// Rotacionando
	float xnew = myPoint.x * c - myPoint.y * s;
	float ynew = myPoint.x * s + myPoint.y * c;

	// Levando o ponto de volta para a posição original
	myPoint.x = xnew + centerPoint.x;
	myPoint.y = ynew + centerPoint.y;

	return myPoint;
}

float deg2rad(float angle)
{
	return angle * (PI / 180);
}
