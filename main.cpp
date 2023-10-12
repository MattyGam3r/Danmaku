#include <SFML/Graphics.hpp>
//For Debugging
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MainGame.h"
#include "Player.h"
#include "Enemy.h"
#include "Wave.h"

int main() {
  //Defining First Enemy (Froakie)
  sf::Texture* froakieSprite = new sf::Texture;
  froakieSprite->loadFromFile("enemy.png");

  int * numWaves = new int;
  *numWaves = 10;

  Wave ** waves = new Wave*[10];
  for (int i =0; i < 10; i++){
    waves[i] = new Wave;
  }

  int waveIter = 0;

  std::ifstream infile("Stage1.txt");
  
  if (infile.is_open()) {
    int enemyIter = 0;
    Enemy** enemyArray = new Enemy* [10];

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string header = "";

        ss >> header;
        // std::cout << line << std::endl;

          if(header == "h") {
            // std::cout << "h " << std::endl;
            std::string SenemyTime, SenemyCount;
            ss >> SenemyTime >> SenemyCount;
            std::cout << header << " " << SenemyTime << " " << SenemyCount << std::endl;

            int enemyTime = std::stoi(SenemyTime);
            int enemyCount = std::stoi(SenemyCount);
            
            waves[waveIter]->setEnemyTime(enemyTime);
          }
          if(header == "e") {
            std::string enemyName, SxPos, SyPos;
            ss >> enemyName >> SxPos >> SyPos;
            std::cout << header << " " << enemyName << " " << SxPos << " " << SyPos << std::endl;

            int xPos = std::stoi(SxPos);
            int yPos = std::stoi(SyPos);

            // std::cout << "e" << " " << enemyName << " " << xPos << " " << yPos << std::endl;
            enemyArray[enemyIter] = new Enemy (1, sf::Vector2f(0,0.05), froakieSprite, sf::Vector2f(xPos,yPos));
            waves[waveIter]->addEnemy(enemyArray[enemyIter]);
            enemyIter += 1;
          }
          if(header == "c") {
            std::cout << "c" << std::endl;
            waveIter += 1;
          }
    }
    infile.close();
}
  
  // waves[0]->addEnemy(froakieLeft);
  // waves[0]->setEnemyTime(1);
  MainGame game(sf::Vector2f(480,640), "Game", waves, numWaves);
  sf::Time time;
  game.run();


}
