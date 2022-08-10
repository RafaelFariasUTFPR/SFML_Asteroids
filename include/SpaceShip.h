#pragma once
#include "GameObject.h"


#include <iostream>

class SpaceShip
{
public:
    SpaceShip();


    sf::VertexArray objectVertexArr;
    GameObject gameObject;


    //Input handdlers
    void inputLeft();
    void inputRight();


    void process();


    //Getters & Setters
    sf::Vector2f getSpeed() { return speed; }
    float getRotationSpeed() { return rotationSpeed; }
    float getMaxSpeed() { return maxSpeed; }
    float getMaxRotationSpeed() { return maxRotationSpeed; }
    float getRotationAcceleration() { return rotationAcceleration; }
    float getAcceleration() { return acceleration; }

    void setSpeed(sf::Vector2f newSpeed) { speed = newSpeed; }
    void setRotationSpeed(float newRotationSpeed) { rotationSpeed = newRotationSpeed; }
    void setMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed; }
    void setMaxRotationSpeed(float newMaxRotationSpeed) { maxRotationSpeed = newMaxRotationSpeed; }
    void setRotationAcceleration(float newRotationAcceleration) { rotationAcceleration = newRotationAcceleration; }
    void setAcceleration(float newAcceleration) { acceleration = newAcceleration; }
    void setDeltaTime(float newDeltaTime) { deltaTime = newDeltaTime; }



private:
    sf::Vector2f speed;
    float rotationSpeed;
    
    
    float deltaTime;


    //Settings
    float maxSpeed = 0.5;
    float maxRotationSpeed = 0.5;
    float rotationAcceleration = 0.05;
    float acceleration = 0.1;

};

