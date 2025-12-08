

#include "efektytekstowe.h"

EfektTekstowy::EfektTekstowy(sf::Font& font) : czcionka(font) {}

void EfektTekstowy::pokaz(sf::Vector2f pozycja, const std::string& tekst) {
    Efekt nowy;
    nowy.tekst.setFont(czcionka);
    nowy.tekst.setString(tekst);
    nowy.tekst.setPosition(pozycja);
    nowy.tekst.setCharacterSize(20);
    nowy.tekst.setFillColor(sf::Color::Yellow);
    nowy.czas = 20; 
    aktywne.push_back(nowy);
}

void EfektTekstowy::aktualizuj() {
    for (int i = (int)aktywne.size() - 1; i >= 0; --i) {
        aktywne[i].pozycja.y -= 1.f;
        aktywne[i].tekst.setPosition(aktywne[i].pozycja);
        aktywne[i].czas--;
        if (aktywne[i].czas <= 0) {
            aktywne.erase(aktywne.begin() + i);
        }
    }
}

void EfektTekstowy::rysuj(sf::RenderWindow& okno) {
    for (auto& e : aktywne)
        okno.draw(e.tekst);
}
