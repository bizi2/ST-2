// Copyright 2025 UNN-CS

#include "circle.h"
#include <cmath>

const double PI_VAL = 3.14159265358979323846;

CircleData::CircleData(double r) {
    setR(r);
}

void CircleData::updateAllFromR() {
    circ_val = 2.0 * PI_VAL * rad_val;
    area_val = PI_VAL * rad_val * rad_val;
}

void CircleData::updateAllFromC() {
    rad_val = circ_val / (2.0 * PI_VAL);
    area_val = PI_VAL * rad_val * rad_val;
}

void CircleData::updateAllFromA() {
    rad_val = std::sqrt(area_val / PI_VAL);
    circ_val = 2.0 * PI_VAL * rad_val;
}

void CircleData::setR(double r) {
    rad_val = r;
    updateAllFromR();
}

void CircleData::setC(double c) {
    circ_val = c;
    updateAllFromC();
}

void CircleData::setA(double a) {
    area_val = a;
    updateAllFromA();
}

double CircleData::getR() const { return rad_val; }
double CircleData::getC() const { return circ_val; }
double CircleData::getA() const { return area_val; }
