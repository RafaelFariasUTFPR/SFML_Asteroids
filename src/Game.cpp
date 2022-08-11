#include "../include/Game.h"


// Quando o objeto Game for instanciado também criará um objeto window
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


    //for (int i = 0; i < 1000; i++)
    {
        spawnAsteroid();
    }

}

void Game::spawnAsteroid()
{

    int ySpawnPos = random::randomIntInRange(0, screenSizeY);

    //0 == esquerda      || 1 == direita
    int spawnSide = random::randomIntInRange(0, 1);

    int xSpawnPos = 0;
    
    if (spawnSide == 1)
        xSpawnPos = screenSizeX;


    AsteroidMaster tempAst(xSpawnPos, ySpawnPos);
    tempAst.setScreenSizeX(screenSizeX);
    tempAst.setScreenSizeY(screenSizeY);

    asteroidArr.push_back(tempAst);

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



}

void Game::process()
{
    player1.process(deltaTime);
    

    for (int i = 0; i < asteroidArr.size(); i++)
        asteroidArr[i].process(deltaTime);


    
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

    for(int i = 0; i < asteroidArr.size(); i++)
        window.draw(asteroidArr[i].gameObject.vertexArr);


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
