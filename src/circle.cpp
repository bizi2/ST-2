// Copyright 2025 UNN-CS

#include "circle.h"
#include <cmath>

const double PI = 3.14159265358979323846;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    radius_ = radius;
    circumference_ = 2.0 * PI * radius_;
    area_ = PI * radius_ * radius_;
}

void Circle::setCircumference(double circumference) {
    circumference_ = circumference;
    radius_ = circumference_ / (2.0 * PI);
    area_ = PI * radius_ * radius_;
}

void Circle::setArea(double area) {
    area_ = area;
    radius_ = std::sqrt(area_ / PI);
    circumference_ = 2.0 * PI * radius_;
}

double Circle::getRadius() const { return radius_; }
double Circle::getCircumference() const { return circumference_; }
double Circle::getArea() const { return area_; }