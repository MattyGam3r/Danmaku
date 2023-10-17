//MAIN MENU CLASS
//This class hold the main menu, which is the general interface in which
//The user navigates around the game, and controls the main game loop

#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define Max_main_menu 4
class MainMenu
{
private:
    int MainMenuSelected;
    sf::Font font;
    sf::Text mainMenu[Max_main_menu];
public:
    //Creates a main menu, with the specified width and height values of the render window
    MainMenu(float width, float height);
    //Draws the main menu to the render window parsed in
    void draw(sf::RenderWindow *window);
    //Moves the selected menu element upwards by one
    void MoveUp();
    //Moves the selected menu element downwards by one
    void MoveDown();

    //Returns the element of the main menu selected
    int MainMenuPressed()
    {
        return MainMenuSelected;
    }

    //Deconstructor
    ~MainMenu();
};

#endif