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

    void process(double _deltaTime);


    //Getters & Setters

    float getMaxSpeed() { return maxSpeed; }
    float getMaxRotationSpeed() { return maxRotationSpeed; }
    float getRotationAcceleration() { return rotationAcceleration; }
    float getAcceleration() { return acceleration; }

    
    void setMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed; }
    void setMaxRotationSpeed(float newMaxRotationSpeed) { maxRotationSpeed = newMaxRotationSpeed; }
    void setRotationAcceleration(float newRotationAcceleration) { rotationAcceleration = newRotationAcceleration; }
    void setAcceleration(float newAcceleration) { acceleration = newAcceleration; }
    void setDeltaTime(double newDeltaTime);
    void setScreenSizeX(int newSize);
    void setScreenSizeY(int newSize);


private:
    double deltaTime;


    //Settings
    float maxSpeed = 400;
    float acceleration = 100;
    float maxRotationSpeed = 300;
    float rotationAcceleration = 300;

    int screenSizeX;
    int screenSizeY;

};

