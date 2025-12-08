


#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Jedzenie;
class Bonus;

class Waz {
public:
    Waz();
    void obsluzEvent(const sf::Event& e);
    void aktualizuj();
    void rysuj(sf::RenderWindow& okno);
    void urosnij();
    bool kolizja(const Jedzenie& j);
    bool martwy();
    void restart();

    
    const std::vector<sf::RectangleShape>& pobierzCialo() const { return cialo; }
    sf::Vector2f pobierzKierunek() const { return kierunek; }
    void ustawStan(const std::vector<sf::Vector2f>& pozycje, sf::Vector2f kier);

private:
    std::vector<sf::RectangleShape> cialo;
    sf::Vector2f kierunek;
    bool dead;
};
