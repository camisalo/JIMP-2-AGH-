//
// Created by konrad on 24.04.17.
//
#include "Ksztalt.h"

int main(void) {
    Ksztalt *a;
    int k, bok;
    for (int i = 0; i < 10; ++i) {
        k = std::rand() % 3;
        bok = std::rand() % 50;
        if (k == 0)
            a = new Trojkat(bok);
        else if (k == 1)
            a = new Kwadrat(bok);
        else
            a = new Kolo(bok);
        a->rysuj();
    }
    return 0;
}