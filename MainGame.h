//MAIN GAME CLASS
//This class holds the main game loop, which contains players enemies, and renders in the main game
//For the user to play



#ifndef MAINGAME_H
#define MAINGAME_H
#include <SFML/Graphics.hpp>
// For Debugging
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Boss.h"
#include "Enemy.h"
#include "MainMenu.h"
#include "Player.h"
#include "Wave.h"

class MainGame {
 private:
  // Stores the render window which is needed to display the graphics
  sf::RenderWindow* window;
  Player* reimu = new Player();

  // Stores all of the Entity's which have to be drawn into the game
  Entity** drawableObjects;
  // Stores the amount of entities which have to be drawn
  int* numDrawableObjects;
  int* maxDrawableObjects;
  sf::Texture backgroundImage;
  sf::RectangleShape background;
  sf::Texture* froakieSprite;
  // Stores all the waves which will be spawned in the game
  Wave** waves;
  // Stores the number of waves (will need this to loop through 'waves')
  int* numWaves;
  // Stores the highest wave spawned (used to not repeat loops)
  int* waveSpawned = new int;
  double* totalTime = new double;

 public:
 //Default constructor, used to make the game
  MainGame(sf::Vector2f size, std::string title, sf::RenderWindow* window);
  //Deconstructor
  ~MainGame();
  //Starts a main game loop, which contains the game
  bool run();
};

#endif