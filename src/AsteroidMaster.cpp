#include "../include/AsteroidMaster.h"

AsteroidMaster::AsteroidMaster()
{
	generateGeometry(10);
}


AsteroidMaster::AsteroidMaster(int xSpawnPos, int ySpawnPos)
{

    generateGeometry(10);

    gameObject.setPosition(sf::Vector2f(xSpawnPos, ySpawnPos));
}


AsteroidMaster::AsteroidMaster(int xSpawnPos, int ySpawnPos, float size)
{
    generateGeometry(size);
}



void AsteroidMaster::generateGeometry(float asteroidSize)
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