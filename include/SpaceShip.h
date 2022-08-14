#pragma once

#include <iostream>
#include <vector>


#include "GameObject.h"
#include "Bullet.h"
#include "GlobalVariables.h"
#include "AsteroidMaster.h"


class SpaceShip
{
public:
    SpaceShip(std::vector<AsteroidMaster>& _asteroidArrPtr);


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
    bool dead = false;

private:
    sf::Clock localClock;
    std::vector<AsteroidMaster>* asteroidArrPtr;

    //Settings
    float maxSpeed = 400;
    float acceleration = 180;
    float maxRotationSpeed = 300;
    float rotationAcceleration = 400;

    float fireBulletDelay = 300; //in milliseconds


};

