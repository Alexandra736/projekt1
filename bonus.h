#pragma once
#include <SFML/Graphics.hpp>

class Waz;

class Bonus {
public:
    Bonus();
    void rysuj(sf::RenderWindow& okno);
    int sprawdz(const Waz& waz);
    void ustawPozycje(sf::Vector2f p) { shape.setPosition(p); }
    sf::Vector2f pobierzPozycje() const { return shape.getPosition(); }
    void losujNowy();


private:
    sf::CircleShape shape;
    sf::Clock timer;
    bool aktywny;

    
};

