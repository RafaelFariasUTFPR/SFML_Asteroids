#include "../include/Game.h"


// Quando o objeto Game for instanciado também criará um objeto window
Game::Game() : window(sf::VideoMode(global::screenHeight, global::screenWidth), "Asteroids"), player1(asteroidArr)
{

    fps = 0;
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


    for (int i = 0; i < 10; i++)
    {
        spawnAsteroid();
    }

}

void Game::spawnAsteroid()
{

    int ySpawnPos = random::randomIntInRange(0, global::screenHeight);

    //0 == esquerda      || 1 == direita
    int spawnSide = random::randomIntInRange(0, 1);



    AsteroidMaster tempAst(ySpawnPos, spawnSide);

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
    global::deltaTime = calculateDeltaTime();

}

void Game::process()
{  

    player1.process();
    for (int i = 0; i < asteroidArr.size(); i++)
        asteroidArr[i].process();


    
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

    //Drawing Bullets
    for (int i = 0; i < player1.bulletsArr.size(); i++)
    {
        window.draw(player1.bulletsArr[i].gameObject.vertexArr);

        // Desenhando linhas de colisão caso haja
        if (player1.bulletsArr[i].gameObject.collisionDebugLinesArr.size())
        {
            for (int j = 0; j < player1.bulletsArr[i].gameObject.collisionDebugLinesArr.size(); j++)
            {
                window.draw(player1.bulletsArr[i].gameObject.collisionDebugLinesArr.at(j));

            }
        }
    }

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
