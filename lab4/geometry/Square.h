//
// Created by konrad on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <iostream>

namespace geometry {

    class Point {
    public:
        //Konstruktor bezparametrowy
        Point();

        //Konstruktor parametrowy
        Point(double x, double y);

        //Destruktor wykonywany przed zwolnieniem pamięci
        ~Point();

        //Metody nie modyfikujące stanu obiektu (const na końcu metody)
        //nie mogą zmodyfikować tego obiektu.
        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;


        //metody akcesorów są publiczne i tylko w przy ich pomocy
        //można się dostać z zewnątrz do pól klasy
        double GetX() const;

        double GetY() const;

        //metody seterów pozwalające zmienić stan obiektu
        //po jego zainicjalizowaniu
        void SetX(double x);

        void SetY(double y);

    private:
        //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
        double x_, y_;
    };


    class Square {
    public:
        Square();

        Square(Point p1, Point p2, Point p3, Point p4);

        ~Square();

        double Circumference() const;

        double Area() const;

    private:
        Point p1;
        Point p2;
        Point p3;
        Point p4;
        Point p[5] = {p1, p2, p3, p4, p1};
    };
}
#endif //JIMP_EXERCISES_SQUARE_H
