




#include "menu.h"

Menu::Menu(sf::RenderWindow& window) : okno(window), wybrana(0) {

#if defined(_WIN32)
    czcionka.loadFromFile("C:/Windows/Fonts/arial.ttf");
#elif defined(__linux__)
    czcionka.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
#endif

    std::string nazwy[3] = {
        "Nowa gra",
        "Wczytaj zapisana gre",
        "Wyjdz"
    };

    for (int i = 0; i < 3; i++) {
        opcje[i].setFont(czcionka);
        opcje[i].setCharacterSize(36);
        opcje[i].setString(nazwy[i]);
        opcje[i].setPosition(180, 180 + i * 70);
    }
}

//открытие

int Menu::uruchom() {
    while (okno.isOpen()) {
        sf::Event e;

        while (okno.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                okno.close();

            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Up)
                    wybrana = (wybrana + 2) % 3;

                if (e.key.code == sf::Keyboard::Down)
                    wybrana = (wybrana + 1) % 3;

                if (e.key.code == sf::Keyboard::Enter)
                    return wybrana;
            }
        }

        rysuj();
    }
    return 2;
}


//вид
void Menu::rysuj() {
    okno.clear(sf::Color::Black);

    for (int i = 0; i < 3; i++) {
        opcje[i].setFillColor(i == wybrana ? sf::Color::Green : sf::Color::White);
        okno.draw(opcje[i]);
    }

    okno.display();
}
