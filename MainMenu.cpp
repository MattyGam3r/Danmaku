#include "MainMenu.h"

MainMenu::MainMenu(float width, float height){
    if (!font.loadFromFile("Christmas Bell.otf")){
        std::cout << "Couldn't load font" << std::endl;
    }

    //Start Playing The Game
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::Red);
    mainMenu[0].setString(">(Play)<");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400,200);
    //Tutorial Screen (how to play game)
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::Red);
    mainMenu[1].setString("How to Play");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400,300);
    //Leaderboards screen
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::Red);
    mainMenu[2].setString("Leaderboards");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400,400);
    //Exit Game
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::Red);
    mainMenu[3].setString(">(Exit Game)<");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(400,500);

    MainMenuSelected = -1;
}
MainMenu::~MainMenu(){

}

//Draw the Main Menu Screen
void MainMenu::draw(sf::RenderWindow * window){
    for (int i = 0; i < Max_main_menu; i++){
        window->draw(mainMenu[i]);
    }
}

//MoveUp
void MainMenu::MoveUp(){
    if (MainMenuSelected - 1 >= 0){
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);

        MainMenuSelected-= 1;
        if (MainMenuSelected == -1){
            MainMenuSelected = 3;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
    }
}

//Moving the Selection Downwards
void MainMenu::MoveDown(){
    if (MainMenuSelected + 1 <= 4){
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);

        MainMenuSelected+=1;
        if(MainMenuSelected == 4){
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
    }
}