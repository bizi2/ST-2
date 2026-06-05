// Copyright 2025 UNN-CS

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius_;
    double circumference_;
    double area_;

 public:
    explicit Circle(double radius);

    void setRadius(double radius);
    void setCircumference(double circumference);
    void setArea(double area);

    double getRadius() const;
    double getCircumference() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_



