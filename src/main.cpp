#include <SFML/Graphics.hpp>
#include "../include/Game.h"
#include <iostream>


int main()
{
    sf::Vertex vertex[] = {
        sf::Vertex(sf::Vector2f(10, 50), sf::Color::Red),
        sf::Vertex(sf::Vector2f(20, 70), sf::Color::Red),
        sf::Vertex(sf::Vector2f(30, 50), sf::Color::Red),
        sf::Vertex(sf::Vector2f(10, 50), sf::Color::Red)

    };
    

	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroids");
	while (window.isOpen())
	{
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(vertex, 4, sf::LinesStrip);



        window.display();
	}



	return 0;
}