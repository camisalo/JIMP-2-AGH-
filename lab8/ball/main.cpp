//
// Created by konrad on 27.04.17.
//

#include <iostream>

#include "Ball.h"

int main() {
    try {
        drawBall();
    } catch (const BallException &a) {
        cout << "Blad podczas rysowania kola" << endl;
    } catch (const CircleException &b) {
        cout << "Blad podczas rysowania kuli" << endl;
    }
}