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
    double circumference = 0, length;
    int k = 0;
    length = p1.Distance(p2);
    for (int j = 0; j < 3; ++j) {
        for (int i = j + 1; i < 4; ++i) {
            if (length < p[j].Distance(p[i])) {
                length = p[j].Distance(p[i]);
                k = 0;
                circumference = 0;
            } else if (length == p[j].Distance(p[i])) {
                k++;
                circumference += p[j].Distance(p[i]);
            } else {
                cout << k << "za dlugi odcinek" << endl;
            }
        }
    }
    if (k == 4) {
        cout << endl << circumference << endl;
    } else {
        circumference = 0;
    }
    cout << circumference << endl;
    return circumference;
}

double geometry::Square::Area() const {
    double Area = 0, length;
    int k = 0;
    length = p[0].Distance(p[1]);
    for (int j = 0; j < 3; ++j) {
        for (int i = j + 1; i < 4; ++i) {
            if (length < p[j].Distance(p[i])) {
                length = p[j].Distance(p[i]);
                k = 0;
            } else if (length == p[j].Distance(p[i])) {
                k++;
            } else {
                cout << k << "za dlugi odcinek" << endl;
            }
        }
    }
    if (k == 4) {
        Area = p[0].Distance(p[1]) * p[1].Distance(p[2]);
        cout << endl << Area << endl;
    } else {
        Area = 0;
    }
    cout << Area << endl;
    return Area;
}
