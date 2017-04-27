//
// Created by konrad on 27.04.17.
//

#ifndef JIMP_EXERCISES_BALL_H
#define JIMP_EXERCISES_BALL_H


#include <iostream>

using namespace std;

class CircleException {
public:
    CircleException();
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException {
public:
    BallException();
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall();

#endif //JIMP_EXERCISES_BALL_H
