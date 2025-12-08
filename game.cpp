




#include "game.h"
#include <SFML/System.hpp>

Gra::Gra(sf::RenderWindow& okno, bool wczytaj)
    : okno(okno), punkty(0), bonus(), efekt(czcionka)
{
#if defined(_WIN32)
    czcionka.loadFromFile("C:/Windows/Fonts/arial.ttf");
#else
    czcionka.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
#endif
  

    rekord = zapis.pobierzNajlepszy();

    tekstPunkty.setFont(czcionka);
    tekstPunkty.setCharacterSize(18);
    tekstPunkty.setFillColor(sf::Color::White);
    tekstPunkty.setPosition(5, 5);

    tekstBonus.setFont(czcionka);
    tekstBonus.setCharacterSize(28);
    tekstBonus.setFillColor(sf::Color::Cyan);
    tekstBonus.setPosition(180, 5);

    tekstKoniec.setFont(czcionka);
    tekstKoniec.setCharacterSize(48);
    tekstKoniec.setFillColor(sf::Color::Red);
    tekstKoniec.setString("Koniec Gry");
    tekstKoniec.setPosition(150, 250);

    if (wczytaj)
        wczytajGre();
}
//вкл
void Gra::uruchom() {
    sf::Clock zegar;

    while (okno.isOpen()) {
        sf::Event e;
        while (okno.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                okno.close();
            }
            waz.obsluzEvent(e);
        }

        if (zegar.getElapsedTime().asMilliseconds() > 120) {
            aktualizuj();
            zegar.restart();
        }

        rysuj();
    }
}

void Gra::aktualizuj() {

    waz.aktualizuj();

    // стычка с яблочкаит
    if (waz.kolizja(jedzenie)) {
        waz.urosnij();                 
        punkty++;                       
        efekt.pokaz(waz.pobierzCialo()[0].getPosition(), "+1"); 
        jedzenie.losuj();               
    }

    // стычка с бонусом
    int wartosc = bonus.sprawdz(waz);
    if (wartosc != 0) {
        punkty += wartosc;

        std::string tekst = (wartosc > 0 ? "+" : "") + std::to_string(wartosc);
        efekt.pokaz(waz.pobierzCialo()[0].getPosition(), tekst); 

        tekstBonus.setString(wartosc > 0 ? "+2!" : "-2!");
        if (wartosc != 0)
            bonus.losujNowy(); 
    }
    else {
        tekstBonus.setString("");
    }

    // dead
    if (waz.martwy()) {

        if (punkty > rekord) {
            rekord = punkty;
            zapis.zaktualizujNajlepsze(punkty);
        }

        zapiszGre(); 

        okno.clear();
        waz.rysuj(okno);
        jedzenie.rysuj(okno);
        bonus.rysuj(okno);
        okno.draw(tekstKoniec);
        okno.display();

        sf::sleep(sf::seconds(2));

        waz.restart(); 
        punkty = 0;
    }

    efekt.aktualizuj(); 

    // обновка текста
    tekstPunkty.setString(
        "Punkty: " + std::to_string(punkty) +
        "  Rekord: " + std::to_string(rekord)
    );
}

// очевидное рисование
void Gra::rysuj() {
    okno.clear();
    waz.rysuj(okno);
    jedzenie.rysuj(okno);
    bonus.rysuj(okno);
    okno.draw(tekstPunkty);
    okno.draw(tekstBonus);
    okno.display();
}

void Gra::wczytajGre() {
    zapis.wczytajStan(waz, jedzenie, bonus, punkty);
}

void Gra::zapiszGre() {
    zapis.zapiszStan(waz, jedzenie, bonus, punkty);
}












