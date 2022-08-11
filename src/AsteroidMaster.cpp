#include "../include/AsteroidMaster.h"

AsteroidMaster::AsteroidMaster()
{
    radius = 30;
    setup();
}


AsteroidMaster::AsteroidMaster(int xSpawnPos, int ySpawnPos)
{

    radius = 50;
    setup();

    gameObject.setPosition(sf::Vector2f(xSpawnPos, ySpawnPos));
    
}


AsteroidMaster::AsteroidMaster(int xSpawnPos, int ySpawnPos, float size)
{
    radius = size;
    setup();
}


void AsteroidMaster::process(double _deltaTime)
{
    gameObject.setDeltaTime(_deltaTime);
    gameObject.process();
}


void AsteroidMaster::generateGeometry()
{

    
    //Definindo o tipo de linha
    objectVertexArr.setPrimitiveType(sf::LinesStrip);

    //Gerando o formato da nave
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius, -radius/2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius/2, -radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(radius / 2, -radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(+radius, -radius/2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(+radius, radius / 2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(radius / 2 , radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius / 2, radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius, radius/2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius, -radius / 2), sf::Color::White));

    for (int i = 0; i < random::randomIntInRange(0, 5); i++)
    {
        //objectVertexArr[random::randomIntInRange(1, objectVertexArr.getVertexCount()-2)].position += sf::Vector2f(offSet(), offSet());
    
        objectVertexArr[1].position -= sf::Vector2f(offSet(), offSet());
        objectVertexArr[4].position += sf::Vector2f(offSet(), offSet());
        objectVertexArr[5].position -= sf::Vector2f(offSet(), offSet());
        objectVertexArr[7].position += sf::Vector2f(offSet(), offSet());

    }

    /*
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius, -radius/2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius/2, -radius), sf::Color::White));
   
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius / 2, -radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(radius / 2, -radius), sf::Color::White));

    objectVertexArr.append(sf::Vertex(sf::Vector2f(radius / 2, -radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(+radius, -radius/2), sf::Color::White));

    objectVertexArr.append(sf::Vertex(sf::Vector2f(+radius, -radius / 2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(+radius, radius / 2), sf::Color::White));
    
    objectVertexArr.append(sf::Vertex(sf::Vector2f(+radius, radius / 2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(radius / 2 , radius), sf::Color::White));
    
    objectVertexArr.append(sf::Vertex(sf::Vector2f(radius / 2, radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius / 2, radius), sf::Color::White));
    
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius / 2, radius), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius, radius/2), sf::Color::White));
    
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius, radius / 2), sf::Color::White));
    objectVertexArr.append(sf::Vertex(sf::Vector2f(-radius, -radius / 2), sf::Color::White));

    for (int i = 0; i < random::randomIntInRange(0, 5); i++)
    {
        //objectVertexArr[random::randomIntInRange(1, objectVertexArr.getVertexCount()-2)].position += sf::Vector2f(offSet(), offSet());
    
        objectVertexArr[1].position -= sf::Vector2f(offSet(), offSet());
        objectVertexArr[2].position = objectVertexArr[1].position;

        objectVertexArr[6].position -= sf::Vector2f(offSet(), offSet());
        objectVertexArr[5].position = objectVertexArr[6].position;

        objectVertexArr[10].position -= sf::Vector2f(offSet(), offSet());
        objectVertexArr[9].position = objectVertexArr[10].position;
        
        objectVertexArr[14].position += sf::Vector2f(offSet(), offSet());
        objectVertexArr[13].position = objectVertexArr[14].position;

    }
    
    
    */

    //Setando os vertices do gameObject
    gameObject.vertexArr = objectVertexArr;

    gameObject.setRotation(random::randomIntInRange(0, 360));

    
}

void AsteroidMaster::setup()
{
    generateGeometry();
    gameObject.screenWrap = true;
    gameObject.setWrapOffset(1.2 * radius, 1.2 * radius);
    gameObject.setSpeed(sf::Vector2f(100, 30));
}

float AsteroidMaster::offSet()
{
    float multiplier = 2.0f / random::randomIntInRange(15, 30);
    return (-multiplier * radius);
}