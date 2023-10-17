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
  //Main Menu Screen
  sf::RectangleShape mainMenuBackground;
  sf::Texture * mainMenuBackgroundArt = new sf::Texture;
  mainMenuBackground.setSize(sf::Vector2f(480,640));
  mainMenuBackground.setPosition(0,0);
  mainMenuBackgroundArt->loadFromFile("MenuBackground.png");
  mainMenuBackground.setTexture(mainMenuBackgroundArt);
  //Win Screen
  sf::RectangleShape winBackground;
  sf::Texture * winBackgroundArt = new sf::Texture;
  winBackground.setSize(sf::Vector2f(480,640));
  winBackground.setPosition(0,0);
  winBackgroundArt->loadFromFile("WinScreen.png");
  winBackground.setTexture(winBackgroundArt);
  //Lose Screen
  sf::RectangleShape loseBackground;
  sf::Texture * loseBackgroundArt = new sf::Texture;
  loseBackground.setSize(sf::Vector2f(480,640));
  loseBackground.setPosition(0,0);
  loseBackgroundArt->loadFromFile("LoseScreen.png");
  loseBackground.setTexture(loseBackgroundArt);
  //Instructions Screen
  sf::RectangleShape Intructionsbackground;
  sf::Texture * instructionsBackgroundArt = new sf::Texture;
  Intructionsbackground.setSize(sf::Vector2f(480,640));
  Intructionsbackground.setPosition(0,0);
  instructionsBackgroundArt->loadFromFile("Instructions.png");
  Intructionsbackground.setTexture(instructionsBackgroundArt);
  double * score = new double;
  *score = 0;



  bool instructionsSelected = false;
  
  sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(480, 640), "MERRY CHRISTMAS!");
  MainMenu * menu = new MainMenu(480, 640);
  MainGame * game;
  bool gameCleared = false;
  bool gameFinished = false;
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
              if (instructionsSelected == true || gameFinished == true){
                gameFinished = false;
                instructionsSelected = false;
              }
              else{
                window->close();
              }
              break;
            case sf::Keyboard::Return:
              switch (menu->MainMenuPressed()){
                  case 0:
                  
                      game = new MainGame(sf::Vector2f(480,640), "Game", window);
                      gameCleared = game->run();
                      gameFinished = true;
                      if (gameCleared == true){
                        std::cout << "You WiN!!!" << std::endl;
                      }
                      delete game;
                      break;
                  case 1:
                      instructionsSelected = true;
                      break;

                  case 2:
                      window->close();
                      break;
              }
              break;
          }
          break;
        case sf::Event::Closed:
          window->close();
          delete mainMenuBackgroundArt;
          delete instructionsBackgroundArt;
          delete score;
          delete window;
          delete menu;
          return 0;

          break;
      }
    }
    window->clear();
    if (gameFinished == true){
      if (gameCleared == true){
        window->draw(winBackground);
      }
      else{
        window->draw(loseBackground);
      }
    }
    else if (instructionsSelected == true){
      window->draw(Intructionsbackground);
    }
    else{
      
      window->draw(mainMenuBackground);
      menu->draw(window);
      
    }
    window->display();
  }
  // waves[0]->addEnemy(froakieLeft);
  // waves[0]->setEnemyTime(1);

}
