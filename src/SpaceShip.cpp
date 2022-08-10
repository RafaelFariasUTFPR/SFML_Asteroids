#include "../include/SpaceShip.h"


SpaceShip::SpaceShip()
{
    //Gerando o formato da nave
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-5, 5), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(0, -10), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(5, 5), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-5, 5), sf::Color::White));

    //Definindo o tipo de linha
    objectVertexArr.setPrimitiveType(sf::LinesStrip);

    //Setando os vertices do gameObject
    gameObject.vertexArr = objectVertexArr;

    

}

void SpaceShip::process()
{
    gameObject.setRotation(gameObject.rotation + (rotationSpeed * deltaTime));
    
    float s = rotationSpeed * deltaTime;

}



void SpaceShip::inputLeft()
{
    float newRotationsSpeed = rotationSpeed - (rotationAcceleration * deltaTime);
    
    if (newRotationsSpeed < -maxRotationSpeed)
        newRotationsSpeed = -maxRotationSpeed;

    setRotationSpeed(newRotationsSpeed);
}
void SpaceShip::inputRight()
{
    float newRotationsSpeed = rotationSpeed + (rotationAcceleration * deltaTime);

    if (newRotationsSpeed > maxRotationSpeed)
        newRotationsSpeed = maxRotationSpeed;

    setRotationSpeed(newRotationsSpeed);
}