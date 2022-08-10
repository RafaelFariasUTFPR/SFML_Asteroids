#include "../include/Game.h"


// Quando o objeto Game for instanciado tamb�m criar� um objeto window
Game::Game() : window(sf::VideoMode(800, 800), "Asteroids")
{

    //Setando o fps
    arialFont.loadFromFile("resources/arial.ttf");
    fpsText.setFont(arialFont);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setCharacterSize(12);

    
}

void Game::beginPlay()
{
    window.setFramerateLimit(500);
    
    //Player setup
    player1.gameObject.setPosition(sf::Vector2f(400, 400));
    player1.setScreenSizeX(screenSizeX);
    player1.setScreenSizeY(screenSizeY);


}

void Game::loop()
{
    preProcess();
    input();
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
            endPlay();
            break;

        }

    }
    //Calculando o FPS
    fps = 1 / deltaTimeClock.getElapsedTime().asSeconds();
    int intFps = (int)fps;
    fpsText.setString("FPS: " + std::to_string(intFps));
    deltaTime = calculateDeltaTime();
    player1.setDeltaTime(deltaTime);



}

void Game::process()
{
    player1.process();
    



    
}


float Game::calculateDeltaTime()
{
	sf::Time time = deltaTimeClock.getElapsedTime();
	deltaTimeClock.restart().asSeconds();

	return time.asSeconds();
}

void Game::draw()
{
    window.clear();

    window.draw(player1.gameObject.vertexArr);
    window.draw(fpsText);

    window.display();
}

void Game::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player1.inputLeft();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player1.inputRight();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player1.inputForward();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        player1.inputFire();


    //Debug keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        window.setFramerateLimit(30);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
        window.setFramerateLimit(400);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
        window.setFramerateLimit(900);

}




//Codigo executado ao fim do jogo
void Game::endPlay()
{

}
