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
#include "MainMenu.h"
int main() {
  //Instructions Screen
  sf::RectangleShape Intructionsbackground;
  sf::Texture * instructionsBackgroundArt = new sf::Texture;
  Intructionsbackground.setSize(sf::Vector2f(480,640));
  Intructionsbackground.setPosition(0,0);
  instructionsBackgroundArt->loadFromFile("Instructions.png");
  Intructionsbackground.setTexture(instructionsBackgroundArt);

  //Defining First Enemy (Froakie)
  sf::Texture* froakieSprite = new sf::Texture;
  froakieSprite->loadFromFile("enemy.png");
  int * numWaves = new int;
  *numWaves = 2;

  Wave ** waves = new Wave*[*numWaves];
  for (int i =0; i < *numWaves; i++){
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
  bool instructionsSelected = false;
  
  sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(480, 640), "MERRY CHRISTMAS!");
  MainMenu * menu = new MainMenu(480, 640);
  MainGame * game = new MainGame(sf::Vector2f(480,640), "Game", waves, numWaves, window);
  while (window->isOpen()){
    sf::Event event;
    

    while (window->pollEvent(event)){
      switch (event.type){

        case sf::Event::KeyReleased:
          switch (event.key.code){
            case sf::Keyboard::Up:
              menu->MoveUp();
              break;
            
            case sf::Keyboard::Down:
              menu->MoveDown();
              break;
            case sf::Keyboard::Escape:
              if (instructionsSelected == true){
                instructionsSelected = false;
              }
              else{
                window->close();
              }
              break;
            case sf::Keyboard::Return:
              switch (menu->MainMenuPressed()){
                  case 0:
                      game->run();
                      break;
                  case 1:
                      instructionsSelected = true;
                      break;

                  case 3:
                      window->close();
                      break;
              }
              break;
          }
          break;
        case sf::Event::Closed:
          window->close();

          break;
      }
    }
    window->clear();

    
    if (instructionsSelected == true){
      window->draw(Intructionsbackground);
    }
    else{
      menu->draw(window);
    }
    window->display();
  }
  // waves[0]->addEnemy(froakieLeft);
  // waves[0]->setEnemyTime(1);

}
