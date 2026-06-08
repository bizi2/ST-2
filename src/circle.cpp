// Copyright 2025 UNN-CS
// Nazyrov A.A.

#include <cmath>
#include "circle.h"


const double PI_NUM = 3.14159265358979323846;

MyCircle::MyCircle(double rad) {
    setRad(rad);
}

void MyCircle::refreshFromR() {
    len_val = 2.0 * PI_NUM * rad_val;
    sq_val = PI_NUM * rad_val * rad_val;
}

void MyCircle::refreshFromLen() {
    rad_val = len_val / (2.0 * PI_NUM);
    sq_val = PI_NUM * rad_val * rad_val;
}

void MyCircle::refreshFromSq() {
    rad_val = std::sqrt(sq_val / PI_NUM);
    len_val = 2.0 * PI_NUM * rad_val;
}

void MyCircle::setRad(double rad) {
    if (rad >= 0.0) {
        rad_val = rad;
        refreshFromR();
    }
}

void MyCircle::setLen(double len) {
    if (len >= 0.0) {
        len_val = len;
        refreshFromLen();
    }
}

void MyCircle::setSq(double sq) {
    if (sq >= 0.0) {
        sq_val = sq;
        refreshFromSq();
    }
}

double MyCircle::getRad() const { return rad_val; }
double MyCircle::getLen() const { return len_val; }
double MyCircle::getSq() const { return sq_val; }

