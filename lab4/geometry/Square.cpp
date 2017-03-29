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
    this->p[0] = p1;
    this->p[1] = p2;
    this->p[2] = p3;
    this->p[3] = p4;

}

geometry::Square::~Square() {}

double geometry::Square::Circumference() const {
    double circumference = 0, length = 0;
    int k = 0;
    length = this->p[0].Distance(this->p[1]);
    for (int j = 0; j < 3; ++j) {
        for (int i = j + 1; i < 4; ++i) {
            cout << endl << "krok: j=" << j << " i=" << i << " odleglosc= " << this->p[j].Distance(this->p[i]) << endl;
            if (length > this->p[j].Distance(this->p[i])) {
                length = this->p[j].Distance(this->p[i]);
                k = 1;
                circumference = this->p[j].Distance(this->p[i]);
                cout << "pierwsze" << endl;
            } else if (length == this->p[j].Distance(this->p[i])) {
                k++;
                circumference += this->p[j].Distance(this->p[i]);
                cout << "sumowanie: " << circumference << " dla k= " << k << endl;
            } else {
                cout << k << "za dlugi odcinek" << endl;
            }
        }
    }
    if (k == 4) {

    } else {
        circumference = 0;
    }
    cout << "wynik circumference = " << circumference << endl;
    return circumference;
}

double geometry::Square::Area() const {
    double area = 0, length = 0;
    int k = 0;
    length = this->p[0].Distance(this->p[1]);
    for (int j = 0; j < 3; ++j) {
        for (int i = j + 1; i < 4; ++i) {
            cout << endl << "krok: j=" << j << " i=" << i << " odleglosc= " << this->p[j].Distance(this->p[i]) << endl;
            if (length > this->p[j].Distance(this->p[i])) {
                length = this->p[j].Distance(this->p[i]);
                k = 1;
                cout << "pierwsze" << endl;
            } else if (length == this->p[j].Distance(this->p[i])) {
                k++;
            } else {
                cout << k << "za dlugi odcinek" << endl;
            }
        }
    }
    if (k == 4) {
        area = length * length;
    } else {
        area = 0;
    }
    cout << "wynik area = " << area << endl;
    return area;
}
