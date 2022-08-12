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

void SpaceShip::process()
{
    gameObject.process();


    for (int i = 0; i < bulletsArr.size(); i++)
    {
        //std::cout << i << "\n";
        bulletsArr.at(i).process();
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
    Bullet tempBullet(gameObject.position, gameObject.getSpeed(), gameObject.rotation);
    
    bulletsArr.push_back(tempBullet);
}





