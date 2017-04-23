#include "Point.h"
#include <iomanip>
#include <iostream>

using ::std::cout;
using ::std::endl;
using ::std::istream;
using ::std::ws;

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

double Point::distance(const Point &sPoint) const {
    return sqrt(pow(x_, 2) + pow(y_, 2));
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


//Helper functions:
void runtime_error(std::string text) {
    std::cout << text << std::endl;
}

void CheckNextChar(char c, istream *is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream *is) {
    (*is) >> ws;
}

double ReadNumber(istream *is) {
    double d;
    (*is) >> d;
    return d;
}

istream &operator>>(istream &input, Point &p) {
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}