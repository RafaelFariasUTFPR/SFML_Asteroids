#include "../include/Game.h"


// Quando o objeto Game for instanciado também criará um objeto window
Game::Game() : window(sf::VideoMode(800, 800), "Asteroids")
{

}

void Game::beginPlay()
{
    running = true;
	spaceShip.gameObject.setPosition(sf::Vector2f(400, 400));




    window.setFramerateLimit(120);



    

}

void Game::loop()
{
    preProcess();
    process();
    draw();
}

void Game::preProcess()
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
    //Calculando o FPS
    fps = 1 / deltaTimeClock.getElapsedTime().asSeconds();
    std::cout << fps << std::endl;
    deltaTime = calculateDeltaTime();



}

void Game::process()
{
    spaceShip.gameObject.setRotation(spaceShip.gameObject.rotation + (0.1 * deltaTime));




    
}


float Game::calculateDeltaTime()
{
	sf::Time time = deltaTimeClock.getElapsedTime();
	deltaTimeClock.restart().asMilliseconds();

	return time.asMilliseconds();
}

void Game::draw()
{
    window.clear();

    window.draw(spaceShip.gameObject.vertexArr);


    window.display();
}

void Game::physicsProcess()
{
    while (running)
    {
        std::cout << "Running" << std::endl;
    }
}