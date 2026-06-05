// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorSetsRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, ConstructorCalculatesCircumference) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * 3.141592653589793 * 5.0);
}

TEST(CircleTest, ConstructorCalculatesArea) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 25.0);
}

TEST(CircleTest, SetRadiusUpdatesValues) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * 3.141592653589793 * 10.0);
}

TEST(CircleTest, SetCircumferenceUpdatesRadius) {
    Circle c(1.0);
    c.setCircumference(2.0 * 3.141592653589793 * 5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(3.141592653589793 * 100.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(RopeGapTest, GapIsPositive) {
    double gap = ropeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(RopeGapTest, GapAboutFifteenCentimeters) {
    double gap = ropeGap();
    EXPECT_NEAR(gap, 0.159, 0.01);
}

TEST(PoolCostsTest, ConcreteCostPositive) {
    double concrete = 0.0, fence = 0.0;
    poolCosts(concrete, fence);
    EXPECT_GT(concrete, 0.0);
}

TEST(PoolCostsTest, FenceCostPositive) {
    double concrete = 0.0, fence = 0.0;
    poolCosts(concrete, fence);
    EXPECT_GT(fence, 0.0);
}

TEST(PoolCostsTest, ConcreteCostValue) {
    double concrete = 0.0, fence = 0.0;
    poolCosts(concrete, fence);
    EXPECT_NEAR(concrete, 21991.0, 10.0);
}

TEST(PoolCostsTest, FenceCostValue) {
    double concrete = 0.0, fence = 0.0;
    poolCosts(concrete, fence);
    EXPECT_NEAR(fence, 50265.0, 10.0);
}

TEST(PoolCostsTest, TotalCostPositive) {
    double concrete = 0.0, fence = 0.0;
    poolCosts(concrete, fence);
    EXPECT_GT(concrete + fence, 0.0);
}
