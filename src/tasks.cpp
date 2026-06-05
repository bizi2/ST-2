// Copyright 2025 UNN-CS

#include "tasks.h"
#include "circle.h"

#include <cmath>

const double EARTH_RADIUS = 6378.1 * 1000.0;

double ropeGap() {
    Circle earth(EARTH_RADIUS);
    double newLength = earth.getCircumference() + 1.0;
    Circle newCircle(0.0);
    newCircle.setCircumference(newLength);
    return newCircle.getRadius() - EARTH_RADIUS;
}

void poolCosts(double& concreteCost, double& fenceCost) {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double CONCRETE_PRICE = 1000.0;
    const double FENCE_PRICE = 2000.0;

    Circle pool(POOL_RADIUS);
    Circle withPath(POOL_RADIUS + PATH_WIDTH);

    double pathArea = withPath.getArea() - pool.getArea();
    double fenceLength = withPath.getCircumference();

    concreteCost = pathArea * CONCRETE_PRICE;
    fenceCost = fenceLength * FENCE_PRICE;
}

