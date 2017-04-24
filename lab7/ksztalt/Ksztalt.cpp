//
// Created by konrad on 24.04.17.
//

#include "Ksztalt.h"

using std::cout;
using std::endl;

Ksztalt::Ksztalt() {}

void Ksztalt::rysuj() {
    cout << " gr " << endl;
}


Trojkat::Trojkat(int a) : a_{a} {}

void Trojkat::rysuj() {
    cout << "rysuje: <<<TRÓJKAT>>> o boku: a = " << a_ << endl;
}

Kwadrat::Kwadrat(int a) : a_{a} {}

void Kwadrat::rysuj() {
    cout << "rysuje: <<<KWADRAT>>> o boku: a = " << a_ << endl;
}

Kolo::Kolo(int r) : r_{r} {}

void Kolo::rysuj() {
    cout << "rysuje: <<<KOŁO>>> o  promieniu: r = " << r_ << endl;
}