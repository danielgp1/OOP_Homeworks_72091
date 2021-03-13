#include <iostream>
#include <cstring>
#include "FilmRanking.h"

int main()
{
    Film f3("Yes", "No", 3);
    Film f2("Help", "David", 2);
    Film f1("Bomb", "Daniel", 6);
    Film films[3] = { f3,f2,f1 };
    Film filmi[2] = { f3,f1 };
    FilmRanking r1(films, 3);
    FilmRanking r2(filmi, 2);
    r1.TopFilms(3);
    r2 = r1;
    r2.TopFilms(3);

    return 0;
}
