//
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

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

// Deklaracja znajduje się w pliku Point.h
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>
#include <iostream>

////////////////////////     POINT    ///////////////////
class Point {
public:
    Point(double x, double y);

    virtual ~Point();
    void SetX(double x);
    void SetY(double y);

    double distance(const Point &sPoint) const;

protected:
    double x_, y_;
};

////////////////////////     POINT  3D    ///////////////////
class Point3d : public Point {
public:
    Point3d(double x, double y, double z);

    virtual ~Point3d();

    void SetZ(double z);

    virtual double distance(Point3d sPoint3d);

private:
    double z_;
};
std::istream &operator>>(std::istream &is, Point &point);

#endif

#endif //JIMP_EXERCISES_POINT_H


