


#include "bonus.h"
#include "waz.h"
#include <cstdlib>

Bonus::Bonus() : aktywny(false) {
    shape.setRadius(10);
    shape.setFillColor(sf::Color::Magenta);
    shape.setOrigin(10, 10);
}

void Bonus::losujNowy() {
    int x = (std::rand() % 30) * 20 + 10;
    int y = (std::rand() % 30) * 20 + 10;
    shape.setPosition({ (float)x, (float)y });
    aktywny = true;
}

void Bonus::rysuj(sf::RenderWindow& okno) {
    if (!aktywny) {
        if (timer.getElapsedTime().asSeconds() > 7 + rand() % 7) {
            losujNowy();
            timer.restart();
        }
        return;
    }
    okno.draw(shape);
}

int Bonus::sprawdz(const Waz& waz) {
    if (!aktywny) return 0;

    // проверка стычек
    auto glowa = waz.pobierzCialo()[0].getGlobalBounds();
    auto kolko = shape.getGlobalBounds();

    if (glowa.intersects(kolko)) {
        aktywny = false;       // для исчезания
        timer.restart();       
        return (rand() % 2 == 0) ? 2 : -2;
    }
    return 0;
}
