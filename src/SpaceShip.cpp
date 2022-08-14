#include "../include/SpaceShip.h"


SpaceShip::SpaceShip(std::vector<AsteroidMaster>& _asteroidArrPtr)
{
    //Definindo o tipo de linha
    objectVertexArr.setPrimitiveType(sf::LinesStrip);

    //Gerando o formato da nave
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-5, 5), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(0, -10), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(5, 5), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-5, 5), sf::Color::White));


    //Setando os vertices do gameObject
    gameObject.vertexArr = objectVertexArr;
    
    gameObject.screenWrap = true;
    gameObject.setWrapOffset(5, 5);
    
    asteroidArrPtr = &_asteroidArrPtr;

}

void SpaceShip::process()
{
    //asteroidArrPtr->at(0).gameObject.vertexArr[0].color = sf::Color::Red;

    gameObject.process();


    for (int i = 0; i < bulletsArr.size(); i++)
    {
        bulletsArr.at(i).process();
        if (bulletsArr.at(i).expired)
        {
            bulletsArr.erase(bulletsArr.begin() + i);
        }

    }

    gameObject.collisionDebugLinesArr.clear();
    for (int i = 0; i < asteroidArrPtr->size(); i++)
    {
        if (gameObject.isOverlapping(asteroidArrPtr->at(i).gameObject.vertexArr, asteroidArrPtr->at(i).gameObject.position))
        {
            //asteroidArrPtr->at(i).destroyed();
            dead = true;
            return;
        }
    }

}



void SpaceShip::inputLeft()
{
    double newRotationsSpeed = gameObject.getRotationSpeed() - (rotationAcceleration * global::deltaTime);
    
    if (newRotationsSpeed < -maxRotationSpeed)
        newRotationsSpeed = -maxRotationSpeed;

    gameObject.setRotationSpeed(newRotationsSpeed);
}
void SpaceShip::inputRight()
{
    double newRotationsSpeed = gameObject.getRotationSpeed() + (rotationAcceleration * global::deltaTime);

    if (newRotationsSpeed > maxRotationSpeed)
        newRotationsSpeed = maxRotationSpeed;
    gameObject.setRotationSpeed(newRotationsSpeed);
}
void SpaceShip::inputForward()
{
    double sinMultiplier = sin(gameObject.rotationRadians); // Eixo X
    double cosMultiplier = -cos(gameObject.rotationRadians); // Eixo y

    sf::Vector2f tempSpeedVector((acceleration * sinMultiplier * global::deltaTime), (acceleration * cosMultiplier * global::deltaTime));
    sf::Vector2f newSpeed = (gameObject.getSpeed() + tempSpeedVector);


    /*
    float mod = sqrt(pow(newSpeed.x, 2) + pow(newSpeed.y, 2));

    if(mod <= maxSpeed)
        setSpeed(newSpeed);

    std::cout << mod << std::endl;

    */

    if (newSpeed.x > maxSpeed)
        newSpeed.x = maxSpeed;
    
    if (newSpeed.y > maxSpeed)
        newSpeed.y = maxSpeed;
    
    gameObject.setSpeed(newSpeed);
}

void SpaceShip::inputFire()
{
    sf::Time time = localClock.getElapsedTime();
    if (time.asMilliseconds() > fireBulletDelay)
    {
        localClock.restart().asMilliseconds();
        Bullet tempBullet(gameObject.position, gameObject.getSpeed(), gameObject.rotation, *asteroidArrPtr);
        
        bulletsArr.push_back(tempBullet);
    }

}





