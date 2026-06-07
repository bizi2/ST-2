// Copyright 2025 UNN-CS


#include "tasks.h"
#include "circle.h"


const double EARTH_R = 6378.1 * 1000.0;

double calcRopeGap() {
    CircleData earthObj(EARTH_R);
    double oldLen = earthObj.getC();
    double newLen = oldLen + 1.0;
    CircleData newObj(0.0);
    newObj.setC(newLen);
    return newObj.getR() - EARTH_R;
}

void calcPoolCosts(double& concreteOut, double& fenceOut) {
    const double POOL_R = 3.0;
    const double PATH_W = 1.0;
    const double CONCRETE_PR = 1000.0;
    const double FENCE_PR = 2000.0;

    CircleData poolObj(POOL_R);
    CircleData totalObj(POOL_R + PATH_W);

    double poolAreaVal = poolObj.getA();
    double totalAreaVal = totalObj.getA();
    double pathAreaVal = totalAreaVal - poolAreaVal;
    double fenceLenVal = totalObj.getC();

    concreteOut = pathAreaVal * CONCRETE_PR;
    fenceOut = fenceLenVal * FENCE_PR;
}

