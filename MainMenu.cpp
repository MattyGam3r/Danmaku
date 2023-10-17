#include "MainMenu.h"
#include <iostream>
MainMenu::MainMenu(float width, float height){
    MainMenuSelected = 0;
    if (!font.loadFromFile("Christmas Bell.otf")){
        std::cout << "Couldn't load font" << std::endl;
    }

    //Start Playing The Game
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::Green);
    mainMenu[0].setString(">(Play)<");
    mainMenu[0].setCharacterSize(50);
    mainMenu[0].setPosition(120,350);
    //Tutorial Screen (how to play game)
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::Red);
    mainMenu[1].setString(">(How to Play)<");
    mainMenu[1].setCharacterSize(50);
    mainMenu[1].setPosition(50,400);
    //Leaderboards screen
    //mainMenu[2].setFont(font);
    //mainMenu[2].setFillColor(sf::Color::Red);
    //mainMenu[2].setString(">(Leaderboards)<");
    //mainMenu[2].setCharacterSize(50);
    //mainMenu[2].setPosition(50,450);
    //Exit Game
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::Red);
    mainMenu[2].setString(">(Exit Game)<");
    mainMenu[2].setCharacterSize(50);
    mainMenu[2].setPosition(80,500);


}
MainMenu::~MainMenu(){
    //delete this;
}

//Draw the Main Menu Screen
void MainMenu::draw(sf::RenderWindow * window){
    for (int i = 0; i < Max_main_menu; i++){
        window->draw(mainMenu[i]);
    }
}

//MoveUp
void MainMenu::MoveUp(){
    if (MainMenuSelected - 1 >= -1){
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);


        MainMenuSelected-= 1;
        if (MainMenuSelected == -1){
            MainMenuSelected = 3;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Green);
    }
}

//Moving the Selection Downwards
void MainMenu::MoveDown(){
    if (MainMenuSelected + 1 <= Max_main_menu){
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);

        MainMenuSelected+=1;
        if(MainMenuSelected == 4){
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Green);
    }
}