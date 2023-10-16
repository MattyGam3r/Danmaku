#ifndef MAINGAME_H
#define MAINGAME_H
#include <SFML/Graphics.hpp>
//For Debugging
#include <iostream>
#include <cmath>
#include <string>
#include "Enemy.h"
#include "Player.h"
#include "Wave.h"
#include "MainMenu.h"
class MainGame {
 private:
  //Stores the render window which is needed to display the graphics
  sf::RenderWindow* window;
  Player* reimu;
  sf::View* view;

  //Stores all of the Entity's which have to be drawn into the game
  Entity ** drawableObjects;
  //Stores the amount of entities which have to be drawn
  int *numDrawableObjects;
  int *maxDrawableObjects;
  double totalTime;
  sf::Texture backgroundImage;
  sf::RectangleShape background;
  //Stores all the waves which will be spawned in the game
  Wave ** waves;
  //Stores the number of waves (will need this to loop through 'waves')
  int * numWaves;
  //Stores the highest wave spawned (used to not repeat loops)
  int * waveSpawned = new int;
 public:
  MainGame(sf::Vector2f size, std::string title, Wave ** waves, int * numWaves, sf::RenderWindow * window) {
    this->window = window;
    reimu = new Player();
    window->setFramerateLimit(60);
    drawableObjects = new Entity * [1000];
    numDrawableObjects = new int;
    *numDrawableObjects = 0;
    maxDrawableObjects = new int;
    *maxDrawableObjects = 1000; 
    //this->numWaves = new int ;
    this->numWaves = numWaves;
    double * totalTime = new double;
    this->waves = waves;
    *waveSpawned = 0;
    *totalTime = 0;

    //For the Background
    background.setSize(sf::Vector2f(1000,1000));
    background.setPosition(sf::Vector2f(0,0));
    backgroundImage.loadFromFile("background.jpg");
    background.setTexture(&backgroundImage);

  }

  
  void run() {
    sf::Font life;
    sf::Clock clock;
    while (window->isOpen()) {
      sf::Event e;
      sf::Time timeElapsed = clock.restart();
      while (window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
          window->close();
          delete reimu;
          delete window;
          return;
        }
        if (e.type == sf::Event::KeyPressed){
          if (e.key.code == sf::Keyboard::Escape){
            window->close();
          }
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        reimu->move_right(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        reimu->move_left(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        reimu->move_up(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        reimu->move_down(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        reimu->shoot(drawableObjects, numDrawableObjects, maxDrawableObjects, totalTime);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        reimu->setSpeed(0.1);
      }else{
        reimu->setSpeed(0.3);
      }

      //Checking if any more Waves need to be Initialised
      for (int i = *waveSpawned; i < (*numWaves); i++){
        std::cout << i;
        if (waves[i]->getEnemyTime() == floor(totalTime)){
          std::cout << "Wave Spawned | ";
          waves[i]->SpawnEnemies(drawableObjects, numDrawableObjects, maxDrawableObjects, waveSpawned);
        }
      }
      
      window->clear();
      window->draw(background);
      reimu->draw(window);
      //Update all the entities
      std::cout << "Drawable Objects: " << *numDrawableObjects;
      for (int i = 0; i < *numDrawableObjects; i++){
        drawableObjects[i]->update(timeElapsed.asMilliseconds(),window);

          //Check for collision
          for (int j = i+1; j < *numDrawableObjects; j++){
            if (pow((drawableObjects[i]->getSprite().getPosition().x - drawableObjects[j]->getSprite().getPosition().x),2) + pow(drawableObjects[i]->getSprite().getPosition().y - drawableObjects[j]->getSprite().getPosition().y,2) <= (drawableObjects[i]->getDepth() + drawableObjects[j]->getDepth())){
              //Checking that two enemies, or bullets (enemy or player) aren't colliding with eachother
              if (drawableObjects[i]->getTag() != drawableObjects[j]->getTag() && !((drawableObjects[i]->getTag() == "enemy" && drawableObjects[j]->getTag() == "enemybullet") || (drawableObjects[i]->getTag() == "enemybullet" && drawableObjects[j]->getTag()=="enemy"))&&
               !((drawableObjects[i]->getTag() == "playerbullet" && drawableObjects[j]->getTag() == "enemybullet") ||(drawableObjects[i]->getTag() == "enemybullet" && drawableObjects[j]->getTag() == "playerbullet"))){
                drawableObjects[i]->getHit(drawableObjects, numDrawableObjects, &i);
                drawableObjects[j]->getHit(drawableObjects, numDrawableObjects, &j);
                std::cout << "Hit!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
              }
            }
          }
          //Check for player-enemy collision
          if(pow((drawableObjects[i]->getSprite().getPosition().x - reimu->getSprite()->getPosition().x),2) + pow(drawableObjects[i]->getSprite().getPosition().y - reimu->getSprite()->getPosition().y,2) <= (drawableObjects[i]->getDepth() + reimu->getDepth())){
            if (drawableObjects[i]->getTag() != "playerbullet"){
              reimu->getHit();
              drawableObjects[i]->getHit(drawableObjects, numDrawableObjects, &i);
            }
          }
        //Checking if any of the sprites are out of bounds, if they are: then it deletes them
        if (drawableObjects[i]->getSprite().getPosition().x < -50 || drawableObjects[i]->getSprite().getPosition().y < 0 || drawableObjects[i]->getSprite().getPosition().y > 700){
          for (int j = i; j < *numDrawableObjects-1; j++){
            drawableObjects[j] = drawableObjects[j+1];
          }
          //Sets the drawable objects down by one
          *numDrawableObjects -= 1;
        }
        
        //If the object is an enemy, fire bullet!
        if (drawableObjects[i]->getTag() == "enemy"){
          drawableObjects[i]->shoot(drawableObjects, numDrawableObjects, maxDrawableObjects, totalTime);
        }
      }

      
      totalTime += timeElapsed.asSeconds();
      std::cout << "| Total Time Elapsed " << floor(totalTime) << " | numwaves: " << *numWaves << std::endl;

      //jigg->update(timeElapsed.asMilliseconds(), window);
      window->display();
    }
  }
};

#endif