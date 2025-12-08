#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(sf::RenderWindow& window);
    int uruchom();

private:
    sf::RenderWindow& okno;
    sf::Font czcionka;
    sf::Text opcje[3];
    int wybrana;

    void rysuj();
};
