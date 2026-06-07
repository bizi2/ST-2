// Copyright 2025 UNN-CS

#ifndef CIRCLE_HEADER_H
#define CIRCLE_HEADER_H

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

#endif
