



#include <SFML/Graphics.hpp>
#include "menu.h"
#include "game.h"

int main() {
    sf::RenderWindow okno(sf::VideoMode(600, 600), "Waz");

    Menu menu(okno);

    while (okno.isOpen()) {
        int wybor = menu.uruchom();

        if (wybor == 0) { // начало
            Gra gra(okno, false);
            gra.uruchom();
        }
        else if (wybor == 1) { // загрузтьб
            Gra gra(okno, true);
            gra.uruchom();
        }
        else if (wybor == 2) { // выйти
            okno.close();
        }
    }

    return 0;
}
