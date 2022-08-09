#include <SFML/Graphics.hpp>
#include "../include/Game.h"
#include "../include/SpaceShip.h"

#include <iostream>
//#include <vector>


int main()
{
    SpaceShip spaceShip;
    spaceShip.gameObject.setPosition(sf::Vector2f(400, 400));
    

	sf::RenderWindow window(sf::VideoMode(800, 800), "Asteroids");
	while (window.isOpen())
	{
        

        
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            
            }
            
        }

        spaceShip.gameObject.setRotation(spaceShip.gameObject.rotation + 0.1);


        window.clear();
        window.draw(spaceShip.gameObject.vertexArr);



        window.display();
	}



	return 0;
}