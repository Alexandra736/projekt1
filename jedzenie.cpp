


#include "jedzenie.h"
#include <cstdlib>
#include <ctime>

Jedzenie::Jedzenie() {
    shape.setSize({ 20,20 });
    shape.setFillColor(sf::Color::Red);
    std::srand((unsigned)std::time(nullptr));
    losuj();
}

void Jedzenie::rysuj(sf::RenderWindow& okno) {
    okno.draw(shape);
}
//генерация
void Jedzenie::losuj() {
    int x = (std::rand() % 30) * 20;
    int y = (std::rand() % 30) * 20;
    shape.setPosition({ (float)x, (float)y });
}
