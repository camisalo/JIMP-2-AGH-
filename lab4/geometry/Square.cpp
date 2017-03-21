//
// Created by konrad on 21.03.17.
//



#include <cmath>
#include <ostream>

#include "Square.h"


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;


geometry::Point::Point() : x_(0), y_(0) {}

geometry::Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
}

geometry::Point::~Point() {}

double geometry::Point::Distance(const Point &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
}

void geometry::Point::ToString(ostream *out) const {
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double geometry::Point::GetX() const {
    return x_;
}

double geometry::Point::GetY() const {
    return y_;
}

void geometry::Point::SetX(double x) {
    x_ = x;
}

void geometry::Point::SetY(double y) {
    y_ = y;
}


geometry::Square::Square() {

}

geometry::Square::Square(Point p1, Point p2, Point p3, Point p4) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
}

geometry::Square::~Square() {}

double geometry::Square::Circumference() const {
    double Circumference = 0;
    for (int i = 0; i < 4; ++i) {
        if (p[0].Distance(p[1]) == p[i].Distance(p[i + 1]))
            Circumference += p[i].Distance(p[i + 1]);
        else {
            cout << "SIEMA" << endl;
            Circumference = 0;
            return Circumference;
        }
    }
    cout << endl << Circumference << endl;
    return Circumference;

}

double geometry::Square::Area() const {
    double Area = 0;
    for (int i = 0; i < 4; ++i) {
        if (p[0].Distance(p[1]) == p[i].Distance(p[i + 1])) {}
        else {
            cout << "SIEMA" << endl;
            return 0;
        }
    }
    Area = p[0].Distance(p[1]) * p[1].Distance(p[2]);
    cout << endl << Area << endl;
    return Area;
}
