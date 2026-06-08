// Copyright 2025 UNN-CS
// Nazyrov A.A.

#include "circle.h"
#include <cmath>

const double PI_NUM = 3.14159265358979323846;

MyCircle::MyCircle(double rad) {
    setRad(rad);
}

void MyCircle::refreshFromR() {
    len_value = 2.0 * PI_NUM * r_value;
    sq_value = PI_NUM * r_value * r_value;
}

void MyCircle::refreshFromLen() {
    r_value = len_value / (2.0 * PI_NUM);
    sq_value = PI_NUM * r_value * r_value;
}

void MyCircle::refreshFromSq() {
    r_value = std::sqrt(sq_value / PI_NUM);
    len_value = 2.0 * PI_NUM * r_value;
}

void MyCircle::setRad(double rad) {
    if (rad >= 0.0) {
        r_value = rad;
        refreshFromR();
    }
}

void MyCircle::setLen(double len) {
    if (len >= 0.0) {
        len_value = len;
        refreshFromLen();
    }
}

void MyCircle::setSq(double sq) {
    if (sq >= 0.0) {
        sq_value = sq;
        refreshFromSq();
    }
}

double MyCircle::getRad() const { return r_value; }
double MyCircle::getLen() const { return len_value; }
double MyCircle::getSq() const { return sq_value; }


