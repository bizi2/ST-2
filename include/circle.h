// Copyright 2025 UNN-CS
// Nazyrov A.A.

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class CircleData {
 private:
    double rad_val;
    double circ_val;
    double area_val;

    void updateAllFromR();
    void updateAllFromC();
    void updateAllFromA();

 public:
    explicit CircleData(double r);

    void setR(double r);
    void setC(double c);
    void setA(double a);

    double getR() const;
    double getC() const;
    double getA() const;
};

#endif  // INCLUDE_CIRCLE_H_

