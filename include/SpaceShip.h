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
    void inputForward();
    void inputFire();

    void process();


    //Getters & Setters
    sf::Vector2f getSpeed() { return speed; }
    double getRotationSpeed() { return rotationSpeed; }
    float getMaxSpeed() { return maxSpeed; }
    float getMaxRotationSpeed() { return maxRotationSpeed; }
    float getRotationAcceleration() { return rotationAcceleration; }
    float getAcceleration() { return acceleration; }

    void setSpeed(sf::Vector2f newSpeed) { speed = newSpeed; }
    void setRotationSpeed(double newRotationSpeed) { rotationSpeed = newRotationSpeed; }
    void setMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed; }
    void setMaxRotationSpeed(float newMaxRotationSpeed) { maxRotationSpeed = newMaxRotationSpeed; }
    void setRotationAcceleration(float newRotationAcceleration) { rotationAcceleration = newRotationAcceleration; }
    void setAcceleration(float newAcceleration) { acceleration = newAcceleration; }
    void setDeltaTime(double newDeltaTime) { deltaTime = newDeltaTime; }
    void setScreenSizeX(int newSize) { screenSizeX = newSize; }
    void setScreenSizeY(int newSize) { screenSizeY = newSize; }


private:
    sf::Vector2f speed;
    double rotationSpeed;
    
    
    double deltaTime;


    //Settings
    float maxSpeed = 400;
    float acceleration = 100;
    float maxRotationSpeed = 300;
    float rotationAcceleration = 300;

    int screenSizeX;
    int screenSizeY;

};

