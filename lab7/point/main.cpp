//
// Created by konrad on 22.04.17.
//

/*
 * Zad 5
 * Konstruktory i destruktory wykonaja sie w kolejnosci:
 * Konstruktor Point
 * Konstruktor Point3d
 * Destruktor Point3d
 * Destruktor Point
 *
 *
 *
 * Zad 6
 * Po wywołaniu metody punkt2d.distance(punkt3d), została wywołana metoda klasy Point(2d).
 * Czyli została zwrócona odległość miedzy punktami na płaszczyźnie 2d.
 * Punkt2d(1,1) , Punkt3d(2,2,2) ------->  1,4121
 *
 *
 *
 */



#include "Point.h"

using ::std::cout;
using ::std::endl;

int main(void) {
    cout << "1. Punkt 2d: " << endl;
    Point punkt2d = Point(1, 1);
    cout << "2. Punkt 3d: " << endl;
    Point3d punkt3d = Point3d(2, 2, 2);

    cout << punkt2d.distance(punkt3d) << endl;

    return 1;
}

