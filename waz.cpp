

#include "waz.h"
#include "jedzenie.h"

Waz::Waz() {
    restart();
}

void Waz::restart() {
    cialo.clear();

    sf::RectangleShape segment({ 20, 20 });
    segment.setFillColor(sf::Color::Green);

    // тело змейки
    for (int i = 0; i < 3; i++) {
        segment.setPosition(300 + i * 20, 300);
        cialo.push_back(segment);
    }

    kierunek = sf::Vector2f(-20, 0);
    dead = false;
}


void Waz::obsluzEvent(const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Up && kierunek.y == 0)
            kierunek = { 0, -20 };
        else if (e.key.code == sf::Keyboard::Down && kierunek.y == 0)
            kierunek = { 0, 20 };
        else if (e.key.code == sf::Keyboard::Left && kierunek.x == 0)
            kierunek = { -20, 0 };
        else if (e.key.code == sf::Keyboard::Right && kierunek.x == 0)
            kierunek = { 20, 0 };
    }
}

//обновка
void Waz::aktualizuj() {
    if (dead) return;

    for (int i = cialo.size() - 1; i > 0; --i)
        cialo[i].setPosition(cialo[i - 1].getPosition());

    cialo[0].move(kierunek);

    sf::Vector2f p = cialo[0].getPosition();
    if (p.x < 0 || p.x >= 600 || p.y < 0 || p.y >= 600)
        dead = true;

    for (size_t i = 1; i < cialo.size(); i++)
        if (cialo[i].getPosition() == p)
            dead = true;
}

void Waz::rysuj(sf::RenderWindow& okno) {
    for (auto& s : cialo)
        okno.draw(s);
}


//рост
void Waz::urosnij() {
    sf::RectangleShape segment({ 20,20 });
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(cialo.back().getPosition());
    cialo.push_back(segment);
}

bool Waz::kolizja(const Jedzenie& j) {
    return cialo[0].getGlobalBounds().intersects(j.pobierzBounds());
}

bool Waz::martwy() {
    return dead;
}

void Waz::ustawStan(const std::vector<sf::Vector2f>& pozycje, sf::Vector2f kier) {
    cialo.clear();
    for (auto& p : pozycje) {
        sf::RectangleShape seg({ 20,20 });
        seg.setFillColor(sf::Color::Green);
        seg.setPosition(p);
        cialo.push_back(seg);
    }
    kierunek = kier;
}
