// Copyright 2025 UNN-CS
// Nazyrov A.A.

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

TEST(MyCircleTest, ConstructorWithRadius) {
    MyCircle fig(5.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 5.0);
}

TEST(MyCircleTest, ConstructorWithZero) {
    MyCircle fig(0.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getLen(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getSq(), 0.0);
}

TEST(MyCircleTest, CircumferenceCalc) {
    MyCircle fig(5.0);
    double expected = 2.0 * 3.141592653589793 * 5.0;
    EXPECT_DOUBLE_EQ(fig.getLen(), expected);
}

TEST(MyCircleTest, AreaCalc) {
    MyCircle fig(5.0);
    double expected = 3.141592653589793 * 25.0;
    EXPECT_DOUBLE_EQ(fig.getSq(), expected);
}

TEST(MyCircleTest, SetRadiusPositive) {
    MyCircle fig(1.0);
    fig.setRad(10.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 10.0);
}

TEST(MyCircleTest, SetLengthPositive) {
    MyCircle fig(1.0);
    fig.setLen(2.0 * 3.141592653589793 * 7.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 7.0);
}

TEST(MyCircleTest, SetAreaPositive) {
    MyCircle fig(1.0);
    fig.setSq(3.141592653589793 * 9.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 3.0);
}

TEST(EarthRopeTest, GapPositive) {
    double gap = calcRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTest, GapValue) {
    double gap = calcRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.01);
}

TEST(PoolCostTest, ConcretePositive) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_GT(concrete, 0.0);
}

TEST(PoolCostTest, FencePositive) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_GT(fence, 0.0);
}

TEST(PoolCostTest, ConcreteExpected) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_NEAR(concrete, 21991.0, 10.0);
}

TEST(PoolCostTest, FenceExpected) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_NEAR(fence, 50265.0, 10.0);
}

