// Copyright 2025 UNN-CS
// Nazyrov A.A.

#ifndef CUSTOM_CIRCLE_H
#define CUSTOM_CIRCLE_H

class MyCircle {
private:
    double r_value;
    double len_value;
    double sq_value;
    
    void refreshFromR();
    void refreshFromLen();
    void refreshFromSq();
    
public:
    explicit MyCircle(double rad);
    
    void setRad(double rad);
    void setLen(double len);
    void setSq(double sq);
    
    double getRad() const;
    double getLen() const;
    double getSq() const;
};

#endif

