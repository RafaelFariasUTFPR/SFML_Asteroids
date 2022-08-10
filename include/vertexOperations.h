#pragma once

#include <math.h>
#include <SFML/Graphics.hpp>

#define PI 3.14159265

sf::Vector2f rotatePointArrounPoint(sf::Vector2f myPoint, sf::Vector2f centerPoint, float rotationAngle);

float deg2rad(float angle);