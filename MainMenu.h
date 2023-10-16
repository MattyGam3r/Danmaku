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
    MainMenu(float width, float height);

    void draw(sf::RenderWindow *window);
    void MoveUp();
    void MoveDown();

    int MainMenuPressed()
    {
        return MainMenuSelected;
    }
    ~MainMenu();
};

#endif