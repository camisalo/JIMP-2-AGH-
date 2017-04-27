//
// Created by konrad on 27.04.17.
//

#include "Ball.h"

CircleException::CircleException() {

}

BallException::BallException() : CircleException() {

}

void drawBall() {
    throw BallException();
}