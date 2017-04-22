#include "Point.h"//
// Created by konrad on 06.04.17.
//

/*
 * Zad 5
 * Konstruktory i destruktory wykonaja sie w kolejnosci:
 * Konstruktor Point
 * Konstruktor Point3d
 * Destruktor Point3d
 * Destruktor Point
 */
using ::std::cout;
using ::std::endl;

////////////////////////     POINT    ///////////////////

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
    cout << "Konstruktor Point" << endl;

}

Point::~Point() {
    cout << "Destruktor Point" << endl;
}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}

////////////////////////     POINT  3D    ///////////////////

Point3d::Point3d(double x, double y, double z) : Point(x, y) {
    z_ = z;
    cout << "Konstruktor Point3d" << endl;
}

Point3d::~Point3d() {
    cout << "Destruktor Point3d" << endl;
}

void Point3d::SetZ(double z) {
    z_ = z;
}

double Point3d::distance(Point3d sPoint3d) {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}