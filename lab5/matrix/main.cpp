//
// Created by konrad on 30.03.17.
//

#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;
using algebra::Matrix;

int main(int argc, char *argv[]) {
    Matrix m1{{1.0i, 0.,   0.},
              {0.,   1.0i, 0.},
              {0.,   0.,   1.0i}};
    Matrix m2{{2.1i, 0.,   0.},
              {1.,   1.0i, 0.},
              {0.,   0.,   1.0i}};

    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;

    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
    cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
    cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;
}