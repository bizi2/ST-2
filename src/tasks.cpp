// Copyright 2025 UNN-CS
// Nazyrov A.A.

#include "tasks.h"
#include "circle.h"
#include <cmath>

const double EARTH_RADIUS_KM = 6378.1;
const double EARTH_RADIUS_M = EARTH_RADIUS_KM * 1000.0;

double earthRopeGap() {
    MyCircle earthObj(EARTH_RADIUS_M);
    double oldLen = earthObj.getLen();
    double newLenVal = oldLen + 1.0;
    MyCircle tempCircle(0.0);
    tempCircle.setLen(newLenVal);
    return tempCircle.getRad() - EARTH_RADIUS_M;
}

void poolCostCalc(double& betonCost, double& fenceCost) {
    const double POOL_RADIUS_VAL = 3.0;
    const double PATH_WIDTH_VAL = 1.0;
    const double BETON_PRICE = 1000.0;
    const double FENCE_PRICE_VAL = 2000.0;
    
    MyCircle poolObj(POOL_RADIUS_VAL);
    MyCircle totalObj(POOL_RADIUS_VAL + PATH_WIDTH_VAL);
    
    double poolAreaNum = poolObj.getSq();
    double totalAreaNum = totalObj.getSq();
    double pathAreaNum = totalAreaNum - poolAreaNum;
    double fenceLenNum = totalObj.getLen();
    
    betonCost = pathAreaNum * BETON_PRICE;
    fenceCost = fenceLenNum * FENCE_PRICE_VAL;
}

