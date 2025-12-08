


#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct Efekt {
    sf::Text tekst;
    sf::Vector2f pozycja;
    int czas; 
};

class EfektTekstowy {
public:
    EfektTekstowy(sf::Font& font);
    void pokaz(sf::Vector2f pozycja, const std::string& tekst);
    void aktualizuj();
    void rysuj(sf::RenderWindow& okno);

private:
    sf::Font& czcionka;
    std::vector<Efekt> aktywne; 
};
