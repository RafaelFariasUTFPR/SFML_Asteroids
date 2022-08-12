#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "GlobalVariables.h"


#include <iostream>
#include <vector>

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

    float getMaxSpeed() { return maxSpeed; }
    float getMaxRotationSpeed() { return maxRotationSpeed; }
    float getRotationAcceleration() { return rotationAcceleration; }
    float getAcceleration() { return acceleration; }

    
    void setMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed; }
    void setMaxRotationSpeed(float newMaxRotationSpeed) { maxRotationSpeed = newMaxRotationSpeed; }
    void setRotationAcceleration(float newRotationAcceleration) { rotationAcceleration = newRotationAcceleration; }
    void setAcceleration(float newAcceleration) { acceleration = newAcceleration; }



    std::vector <Bullet> bulletsArr;


private:


    //Settings
    float maxSpeed = 400;
    float acceleration = 180;
    float maxRotationSpeed = 300;
    float rotationAcceleration = 400;


};

