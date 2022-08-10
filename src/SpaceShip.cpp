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

    

}

void SpaceShip::process()
{
    gameObject.setRotation(gameObject.rotation + (rotationSpeed * deltaTime));
    
    gameObject.setPosition(gameObject.position + sf::Vector2f((speed.x * deltaTime),(speed.y * deltaTime)));


    //Wrapping the screen
    if (gameObject.position.x > screenSizeX)
        gameObject.setPosition(sf::Vector2f(0, gameObject.position.y));
    if (gameObject.position.x < 0)
        gameObject.setPosition(sf::Vector2f(screenSizeX, gameObject.position.y));

    if (gameObject.position.y > screenSizeY)
        gameObject.setPosition(sf::Vector2f(gameObject.position.x, 0));
    if (gameObject.position.y < 0)
        gameObject.setPosition(sf::Vector2f(gameObject.position.x, screenSizeY));

}



void SpaceShip::inputLeft()
{
    double newRotationsSpeed = rotationSpeed - (rotationAcceleration * deltaTime);
    
    if (newRotationsSpeed < -maxRotationSpeed)
        newRotationsSpeed = -maxRotationSpeed;

    setRotationSpeed(newRotationsSpeed);
}
void SpaceShip::inputRight()
{
    double newRotationsSpeed = rotationSpeed + (rotationAcceleration * deltaTime);

    if (newRotationsSpeed > maxRotationSpeed)
        newRotationsSpeed = maxRotationSpeed;

    setRotationSpeed(newRotationsSpeed);
}

void SpaceShip::inputForward()
{
    double sinMultiplier = sin(gameObject.rotationRadians); // Eixo X
    double cosMultiplier = -cos(gameObject.rotationRadians); // Eixo y

    sf::Vector2f tempSpeedVector((acceleration * sinMultiplier * deltaTime), (acceleration * cosMultiplier * deltaTime));
    sf::Vector2f newSpeed = (speed + tempSpeedVector);


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
    
    setSpeed(newSpeed);
}

void SpaceShip::inputFire()
{

}