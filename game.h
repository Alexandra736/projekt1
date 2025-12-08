


#pragma once
#include <SFML/Graphics.hpp>
#include "waz.h"
#include "jedzenie.h"
#include "bonus.h"
#include "menegersave.h"
#include "efektytekstowe.h"



class Gra {
public:
    Gra(sf::RenderWindow& okno, bool wczytaj);
    void uruchom();

private:
    sf::RenderWindow& okno;

    Waz waz;
    Jedzenie jedzenie;
    Bonus bonus;
    MenedzerSave zapis;
    EfektTekstowy efekt;

    int punkty;
    int rekord;

    sf::Font czcionka;
    sf::Text tekstPunkty;
    sf::Text tekstBonus;
    sf::Text tekstKoniec;

    void aktualizuj();
    void rysuj();
    void wczytajGre();
    void zapiszGre();
};
