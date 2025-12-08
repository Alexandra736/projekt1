

#pragma once
#include <SFML/Graphics.hpp>

class Jedzenie {
public:
    Jedzenie();
    void rysuj(sf::RenderWindow& okno);
    void losuj();
    sf::FloatRect pobierzBounds() const { return shape.getGlobalBounds(); }
    sf::Vector2f pobierzPozycje() const { return shape.getPosition(); }
    void ustawPozycje(sf::Vector2f p) { shape.setPosition(p); }

private:
    sf::RectangleShape shape;
};

