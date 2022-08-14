#include "../include/Game.h"


// Quando o objeto Game for instanciado também criará um objeto window
Game::Game(sf::RenderWindow& _window) : player1(asteroidArr)
{
    window = &_window;
    fps = 0;
    //Setando o fps
    arialFont.loadFromFile("resources/arial.ttf");
    fpsText.setFont(arialFont);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setCharacterSize(12);

    
}

void Game::beginPlay()
{
    window->setFramerateLimit(0);
    //window.setVerticalSyncEnabled(true);
    //Player setup
    player1.gameObject.setPosition(sf::Vector2f(400, 400));


    for (int i = 0; i < 10; i++)
    {
        spawnAsteroid(4);
    }

}

void Game::spawnAsteroid(int asteroidSize)
{
    int ySpawnPos = random::randomIntInRange(0, global::screenHeight);

    //0 == esquerda      || 1 == direita
    int spawnSide = random::randomIntInRange(0, 1);



    AsteroidMaster tempAst(ySpawnPos, spawnSide, asteroidSize);

    asteroidArr.push_back(tempAst);

}

void Game::splitAsteroid(sf::Vector2f position, sf::Vector2f velocity, int parentSize, int floatDirection)
{
    for (int i = 0; i < 2; i++)
    {
        sf::Vector2f speedDif(random::randomIntInRange(-5, 5), random::randomIntInRange(-10, 10));


        AsteroidMaster tempAst(position, parentSize - 1, floatDirection);
        tempAst.gameObject.setSpeed(tempAst.gameObject.getSpeed() + speedDif);

        float ySpawnOffset = tempAst.radius;
        if (i)
            ySpawnOffset *= -1;
        tempAst.gameObject.setPosition(tempAst.gameObject.position + sf::Vector2f(random::randomIntInRange((int) -tempAst.radius, (int)tempAst.radius), ySpawnOffset));
        //Separando um pouco no spawn
        

        asteroidArr.push_back(tempAst);


    }
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
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
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
    if (player1.dead)
    {
        restart = true;
        endPlay();
        return;
    }

    for (int i = 0; i < asteroidArr.size(); i++)
    {
        AsteroidMaster *asteroidPtr = &asteroidArr[i];
        AsteroidMaster asteroid = asteroidArr[i];
        asteroidArr[i].process();
        if (asteroid.expired)
        {
            //Deletando o asteroid da array
            asteroidArr.erase(asteroidArr.begin() + i);

            //Caso ele seja grande eu divido ele
            if (asteroid.size > 1)
                splitAsteroid(asteroid.gameObject.position, asteroid.gameObject.getSpeed(), asteroid.size, asteroid.floatDirection);
             

        }
    }


    
}


float Game::calculateDeltaTime()
{
	sf::Time time = deltaTimeClock.getElapsedTime();
	deltaTimeClock.restart().asSeconds();

	return time.asSeconds();
}

void Game::draw()
{


    window->clear();

    window->draw(player1.gameObject.vertexArr);

    for (int i = 0; i < player1.gameObject.collisionDebugLinesArr.size(); i++)
        window->draw(player1.gameObject.collisionDebugLinesArr.at(i));


    for(int i = 0; i < asteroidArr.size(); i++)
        window->draw(asteroidArr[i].gameObject.vertexArr);

    //Drawing Bullets
    for (int i = 0; i < player1.bulletsArr.size(); i++)
    {
        window->draw(player1.bulletsArr[i].gameObject.vertexArr);

        // Desenhando linhas de colisão caso haja
        if (player1.bulletsArr[i].gameObject.collisionDebugLinesArr.size())
        {
            for (int j = 0; j < player1.bulletsArr[i].gameObject.collisionDebugLinesArr.size(); j++)
            {
                window->draw(player1.bulletsArr[i].gameObject.collisionDebugLinesArr.at(j));

            }
        }
    }
    

    window->draw(fpsText);

    window->display();
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
        window->setFramerateLimit(30);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
        window->setFramerateLimit(400);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
        window->setFramerateLimit(900);



}




//Codigo executado ao fim do jogo
void Game::endPlay()
{
    running = false;
}
