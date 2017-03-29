//
// Created by konrad on 21.03.17.
//

#include <ostream>
#include <sstream>

#include "Point.h"

using std::cout;
using std::endl;

int main(void) {
    Point p1(0, 0);
    Point p2(1, 1);

    std::stringstream out;

    out << "pierwszy punkt ma współrzędne: ";
    p1.ToString(&out);
    out << "\ndrógi punkt ma współrzędne: ";
    p2.ToString(&out);
    cout << out.str() << endl;
    cout << "odleglosc miedzy nimi wynosi: " << p1.Distance(p2) << endl;

    return 0;
}