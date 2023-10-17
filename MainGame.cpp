#include "MainGame.h"
MainGame::MainGame(sf::Vector2f size, std::string title,
           sf::RenderWindow* window) {
    // Defining First Enemy (Froakie)
    froakieSprite = new sf::Texture;
    froakieSprite->loadFromFile("enemy.png");
    int* numWavesFile = new int;
    *numWavesFile = 3;

    Wave** wavesFile = new Wave*[*numWavesFile];
    for (int i = 0; i < *numWavesFile; i++) {
      wavesFile[i] = new Wave;
    }

    int waveIter = 0;
    std::ifstream infile("Stage1.txt");

    if (infile.is_open()) {
      int enemyIter = 0;
      Enemy** enemyArray = new Enemy*[10];

      std::string line;
      while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string header = "";

        ss >> header;
        // std::cout << line << std::endl;

        if (header == "h") {
          // std::cout << "h " << std::endl;
          std::string SenemyTime, SenemyCount;
          ss >> SenemyTime >> SenemyCount;
          std::cout << header << " " << SenemyTime << " " << SenemyCount
                    << std::endl;

          int enemyTime = std::stoi(SenemyTime);
          int enemyCount = std::stoi(SenemyCount);

          wavesFile[waveIter]->setEnemyTime(enemyTime);
        }
        if (header == "e") {
          std::string enemyName, SxPos, SyPos;
          ss >> enemyName >> SxPos >> SyPos;
          std::cout << header << " " << enemyName << " " << SxPos << " "
                    << SyPos << std::endl;

          int xPos = std::stoi(SxPos);
          int yPos = std::stoi(SyPos);

          // std::cout << "e" << " " << enemyName << " " << xPos << " " << yPos
          // << std::endl;
          enemyArray[enemyIter] =
              new Enemy(1, sf::Vector2f(0, 0.05), froakieSprite,
                        sf::Vector2f(xPos, yPos));
          wavesFile[waveIter]->addEnemy(enemyArray[enemyIter]);
          enemyIter += 1;
        }
        if (header == "c") {
          std::cout << "c" << std::endl;
          waveIter += 1;
        }
      }
      wavesFile[2] = new Wave();
      wavesFile[2]->setEnemyTime(10);
      Boss * boss = new Boss();
      wavesFile[2]->addEnemy(boss);
    }
      
      infile.close();
      
      this->window = window;
      //window->setFramerateLimit(60);
      drawableObjects = new Entity*[1000];
      numDrawableObjects = new int;
      *numDrawableObjects = 0;
      maxDrawableObjects = new int;
      *maxDrawableObjects = 1000;
      // this->numWaves = new int ;
      this->numWaves = numWavesFile;
      this->waves = wavesFile;
      *waveSpawned = 0;
      *totalTime = 0;

      // For the Background
      background.setSize(sf::Vector2f(1000, 1000));
      background.setPosition(sf::Vector2f(0, 0));
      backgroundImage.loadFromFile("background.jpg");
      background.setTexture(&backgroundImage);
    }
MainGame::~MainGame() {}
bool MainGame::run() {
  sf::Font life;
  sf::Clock clock;
  while (window->isOpen()) {
    bool isEnemy = false;
    sf::Event e;
    sf::Time timeElapsed = clock.restart();
    while (window->pollEvent(e)) {
      if (e.type == sf::Event::Closed) {
        return false;
      }
      if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Escape) {
          return false;
        }
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      reimu->move_right(timeElapsed.asMilliseconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      reimu->move_left(timeElapsed.asMilliseconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      reimu->move_up(timeElapsed.asMilliseconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      reimu->move_down(timeElapsed.asMilliseconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
      reimu->shoot(drawableObjects, numDrawableObjects, maxDrawableObjects,
                   *totalTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      reimu->setSpeed(0.1);
    } else {
      reimu->setSpeed(0.3);
    }

    // Checking if any more Waves need to be Initialised
    for (int i = *waveSpawned; i < (*numWaves); i++) {
      std::cout << i;
      if (waves[i]->getEnemyTime() == floor(*totalTime)) {
        std::cout << "Wave Spawned | ";
        waves[i]->SpawnEnemies(drawableObjects, numDrawableObjects,
                               maxDrawableObjects, waveSpawned);
      }
    }

    window->clear();
    window->draw(background);
    reimu->draw(window);
    // Update all the entities
    std::cout << "Drawable Objects: " << *numDrawableObjects;
    for (int i = 0; i < *numDrawableObjects; i++) {
      drawableObjects[i]->update(timeElapsed.asMilliseconds(), window);

      // Check for collision
      for (int j = i + 1; j < *numDrawableObjects; j++) {
        if (pow((drawableObjects[i]->getSprite().getPosition().x -
                 drawableObjects[j]->getSprite().getPosition().x),
                2) +
                pow(drawableObjects[i]->getSprite().getPosition().y -
                        drawableObjects[j]->getSprite().getPosition().y,
                    2) <=
            (drawableObjects[i]->getDepth() + drawableObjects[j]->getDepth())) {
          // Checking that two enemies, or bullets (enemy or player) aren't
          // colliding with eachother
          if (drawableObjects[i]->getTag() != drawableObjects[j]->getTag() &&
              !((drawableObjects[i]->getTag() == "enemy" &&
                 drawableObjects[j]->getTag() == "enemybullet") ||
                (drawableObjects[i]->getTag() == "enemybullet" &&
                 drawableObjects[j]->getTag() == "enemy")) &&
              !((drawableObjects[i]->getTag() == "playerbullet" &&
                 drawableObjects[j]->getTag() == "enemybullet") ||
                (drawableObjects[i]->getTag() == "enemybullet" &&
                 drawableObjects[j]->getTag() == "playerbullet"))) {
            drawableObjects[i]->getHit(drawableObjects, numDrawableObjects, &i);
            drawableObjects[j]->getHit(drawableObjects, numDrawableObjects, &j);
            std::cout << "Hit!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
          }
        }
      }
      // Check for player-enemy collision
      if (pow((drawableObjects[i]->getSprite().getPosition().x -
               reimu->getSprite()->getPosition().x),
              2) +
              pow(drawableObjects[i]->getSprite().getPosition().y -
                      reimu->getSprite()->getPosition().y,
                  2) <=
          (drawableObjects[i]->getDepth() + reimu->getDepth())) {
        if (drawableObjects[i]->getTag() != "playerbullet") {
          reimu->getHit();
          if (reimu->getHealth() <= 0) {
            return false;
          }

          drawableObjects[i]->getHit(drawableObjects, numDrawableObjects, &i);
        }
      }
      // Checking if any of the sprites are out of bounds, if they are: then
      // it deletes them
      if (drawableObjects[i]->getSprite().getPosition().x < -50 ||
          drawableObjects[i]->getSprite().getPosition().y < 0 ||
          drawableObjects[i]->getSprite().getPosition().y > 700) {
        for (int j = i; j < *numDrawableObjects - 1; j++) {
          drawableObjects[j] = drawableObjects[j + 1];
        }
        // Sets the drawable objects down by one
        *numDrawableObjects -= 1;
      }

      // If the object is an enemy, fire bullet!
      if (drawableObjects[i]->getTag() == "enemy") {
        drawableObjects[i]->shoot(drawableObjects, numDrawableObjects,
                                  maxDrawableObjects, *totalTime);
        isEnemy = true;
      }

      //Checking for win condition
      if (drawableObjects[i]->getTag() == "boss"){
        isEnemy = true;
      }

    }
      if (isEnemy == false && *numWaves == *waveSpawned){
        return true;
      }
    *totalTime += timeElapsed.asSeconds();
    std::cout << "| Total Time Elapsed " << floor(*totalTime)
              << " | numwaves: " << *numWaves << std::endl;

    window->display();
  }
  return true;
}