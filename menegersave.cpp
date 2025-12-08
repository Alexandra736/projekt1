


#include "menegersave.h"
#include <fstream>
#include <algorithm>

static const std::string TOP_FILE = "top.dat";
static const std::string SAVE_FILE = "savegame.dat";

MenedzerSave::MenedzerSave() {
    wczytajTop();
}

void MenedzerSave::wczytajTop() {
    top.clear();
    std::ifstream f(TOP_FILE);
    int v;
    while (f >> v) top.push_back(v);
    f.close();
    while (top.size() < 10) top.push_back(0);
    std::sort(top.rbegin(), top.rend());
}

void MenedzerSave::zapiszTop() {
    std::ofstream f(TOP_FILE);
    for (int v : top) f << v << "\n";
}

void MenedzerSave::zaktualizujNajlepsze(int p) {
    top.push_back(p);
    std::sort(top.rbegin(), top.rend());
    if (top.size() > 10)
        top.pop_back();
    zapiszTop();
}

int MenedzerSave::pobierzNajlepszy() {
    return top.empty() ? 0 : top[0];
}

void MenedzerSave::zapiszStan(const Waz& waz, const Jedzenie& j, const Bonus& b, int punkty) {

    std::ofstream f(SAVE_FILE);

    f << punkty << "\n";

    auto body = waz.pobierzCialo();
    f << body.size() << "\n";

    for (auto& s : body) {
        auto p = s.getPosition();
        f << p.x << " " << p.y << "\n";
    }

    auto kier = waz.pobierzKierunek();
    f << kier.x << " " << kier.y << "\n";

    auto jp = j.pobierzPozycje();
    f << jp.x << " " << jp.y << "\n";

    auto bp = b.pobierzPozycje();
    f << bp.x << " " << bp.y << "\n";

    f.close();
}

void MenedzerSave::wczytajStan(Waz& waz, Jedzenie& j, Bonus& b, int& punkty) {
    std::ifstream f(SAVE_FILE);
    if (!f.good()) return;

    f >> punkty;

    int len;
    f >> len;

    std::vector<sf::Vector2f> pos(len);
    for (int i = 0; i < len; i++)
        f >> pos[i].x >> pos[i].y;

    sf::Vector2f kier;
    f >> kier.x >> kier.y;

    sf::Vector2f jp; f >> jp.x >> jp.y;
    sf::Vector2f bp; f >> bp.x >> bp.y;

    waz.ustawStan(pos, kier);
    j.ustawPozycje(jp);
    b.ustawPozycje(bp);
}
