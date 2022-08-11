#include "../include/SpaceShip.h"


SpaceShip::SpaceShip()
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
    

}

void SpaceShip::process(double _deltaTime)
{
    setDeltaTime(_deltaTime);
    gameObject.process();


}



void SpaceShip::inputLeft()
{
    double newRotationsSpeed = gameObject.getRotationSpeed() - (rotationAcceleration * deltaTime);
    
    if (newRotationsSpeed < -maxRotationSpeed)
        newRotationsSpeed = -maxRotationSpeed;

    gameObject.setRotationSpeed(newRotationsSpeed);
}
void SpaceShip::inputRight()
{
    double newRotationsSpeed = gameObject.getRotationSpeed() + (rotationAcceleration * deltaTime);

    if (newRotationsSpeed > maxRotationSpeed)
        newRotationsSpeed = maxRotationSpeed;
    gameObject.setRotationSpeed(newRotationsSpeed);
}

void SpaceShip::inputForward()
{
    double sinMultiplier = sin(gameObject.rotationRadians); // Eixo X
    double cosMultiplier = -cos(gameObject.rotationRadians); // Eixo y

    sf::Vector2f tempSpeedVector((acceleration * sinMultiplier * deltaTime), (acceleration * cosMultiplier * deltaTime));
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

}

void SpaceShip::setDeltaTime(double newDeltaTime)
{
    deltaTime = newDeltaTime;
    gameObject.setDeltaTime(newDeltaTime);
}

void SpaceShip::setScreenSizeX(int newSize)
{
    screenSizeX = newSize;
    gameObject.setScreenSizeX(newSize);
}

void SpaceShip::setScreenSizeY(int newSize)
{
    screenSizeY = newSize;
    gameObject.setScreenSizeY(newSize);
}