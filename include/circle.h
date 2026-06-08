// Copyright 2025 UNN-CS
// Nazyrov A.A.

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class MyCircle {
 private:
    double rad_val;
    double len_val;
    double sq_val;

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

#endif  // INCLUDE_CIRCLE_H_

