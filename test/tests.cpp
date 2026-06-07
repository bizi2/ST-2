// Copyright 2025 UNN-CS
// Nazyrov A.A.

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

// ===== CircleData tests =====

TEST(CircleDataTest, CreateWithRadius) {
    CircleData c(5.0);
    EXPECT_DOUBLE_EQ(c.getR(), 5.0);
}

TEST(CircleDataTest, CircumferenceFromRadius) {
    CircleData c(5.0);
    EXPECT_DOUBLE_EQ(c.getC(), 2.0 * 3.141592653589793 * 5.0);
}

TEST(CircleDataTest, AreaFromRadius) {
    CircleData c(5.0);
    EXPECT_DOUBLE_EQ(c.getA(), 3.141592653589793 * 25.0);
}

TEST(CircleDataTest, SetRadiusUpdatesAll) {
    CircleData c(1.0);
    c.setR(10.0);
    EXPECT_DOUBLE_EQ(c.getR(), 10.0);
    EXPECT_DOUBLE_EQ(c.getC(), 2.0 * 3.141592653589793 * 10.0);
}

TEST(CircleDataTest, SetCircumferenceUpdatesRadius) {
    CircleData c(1.0);
    c.setC(2.0 * 3.141592653589793 * 7.0);
    EXPECT_DOUBLE_EQ(c.getR(), 7.0);
}

TEST(CircleDataTest, SetAreaUpdatesRadius) {
    CircleData c(1.0);
    c.setA(3.141592653589793 * 9.0);
    EXPECT_DOUBLE_EQ(c.getR(), 3.0);
}

TEST(CircleDataTest, ZeroRadius) {
    CircleData c(0.0);
    EXPECT_DOUBLE_EQ(c.getR(), 0.0);
    EXPECT_DOUBLE_EQ(c.getC(), 0.0);
    EXPECT_DOUBLE_EQ(c.getA(), 0.0);
}

TEST(CircleDataTest, SetNegativeRadiusDoesNothing) {
    CircleData c(5.0);
    c.setR(-10.0);
    EXPECT_DOUBLE_EQ(c.getR(), 5.0);
}

TEST(CircleDataTest, SetNegativeCircumferenceDoesNothing) {
    CircleData c(5.0);
    double oldR = c.getR();
    c.setC(-100.0);
    EXPECT_DOUBLE_EQ(c.getR(), oldR);
}

// ===== Rope gap tests =====

TEST(RopeGapTest, GapPositive) {
    double gap = calcRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(RopeGapTest, GapValue) {
    double gap = calcRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.01);
}

// ===== Pool costs tests =====

TEST(PoolCostsTest, ConcretePositive) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_GT(concrete, 0.0);
}

TEST(PoolCostsTest, FencePositive) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_GT(fence, 0.0);
}

TEST(PoolCostsTest, ConcreteValue) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_NEAR(concrete, 21991.0, 10.0);
}

TEST(PoolCostsTest, FenceValue) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_NEAR(fence, 50265.0, 10.0);
}

TEST(PoolCostsTest, TotalPositive) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_GT(concrete + fence, 0.0);
}

TEST(PoolCostsTest, ZeroPathWidth) {
    CircleData pool(3.0);
    CircleData withPath(3.0);
    double pathArea = withPath.getA() - pool.getA();
    EXPECT_NEAR(pathArea, 0.0, 1e-9);
}

TEST(PoolCostsTest, DifferentPrices) {
    double c1 = 0.0, f1 = 0.0;
    double c2 = 0.0, f2 = 0.0;
    calcPoolCosts(c1, f1);

    const double POOL_R = 3.0;
    const double PATH_W = 1.0;
    CircleData pool(POOL_R);
    CircleData total(POOL_R + PATH_W);
    double pathArea = total.getA() - pool.getA();
    double fenceLen = total.getC();

    c2 = pathArea * 2000.0;
    f2 = fenceLen * 4000.0;

    EXPECT_DOUBLE_EQ(c2, c1 * 2.0);
    EXPECT_DOUBLE_EQ(f2, f1 * 2.0);
}

