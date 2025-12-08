


#pragma once
#include <vector>
#include "waz.h"
#include "jedzenie.h"
#include "bonus.h"

class MenedzerSave {
public:
    MenedzerSave();

    void zaktualizujNajlepsze(int p);
    int pobierzNajlepszy();

    void zapiszStan(const Waz& waz, const Jedzenie& j, const Bonus& b, int punkty);
    void wczytajStan(Waz& waz, Jedzenie& j, Bonus& b, int& punkty);

private:
    std::vector<int> top;
    void wczytajTop();
    void zapiszTop();
};
