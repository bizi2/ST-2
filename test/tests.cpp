// Copyright 2025 UNN-CS
// Nazyrov A.A.

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

// ========== ??????????? ? ???? (6 ??????) ==========
TEST(MyCircleTest, CreateWithPositiveRadius) {
    MyCircle fig(5.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 5.0);
}

TEST(MyCircleTest, CreateWithZero) {
    MyCircle fig(0.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getLen(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getSq(), 0.0);
}

TEST(MyCircleTest, CircumferenceFromRadius) {
    MyCircle fig(5.0);
    double expected = 2.0 * 3.141592653589793 * 5.0;
    EXPECT_DOUBLE_EQ(fig.getLen(), expected);
}

TEST(MyCircleTest, AreaFromRadius) {
    MyCircle fig(5.0);
    double expected = 3.141592653589793 * 25.0;
    EXPECT_DOUBLE_EQ(fig.getSq(), expected);
}

TEST(MyCircleTest, LargeRadius) {
    MyCircle fig(10000.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 10000.0);
}

TEST(MyCircleTest, SmallRadius) {
    MyCircle fig(0.001);
    EXPECT_DOUBLE_EQ(fig.getRad(), 0.001);
}

// ========== ????? setRad (5 ??????) ==========
TEST(MyCircleTest, SetRadiusPositive) {
    MyCircle fig(1.0);
    fig.setRad(10.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 10.0);
    EXPECT_DOUBLE_EQ(fig.getLen(), 2.0 * 3.141592653589793 * 10.0);
    EXPECT_DOUBLE_EQ(fig.getSq(), 3.141592653589793 * 100.0);
}

TEST(MyCircleTest, SetRadiusZero) {
    MyCircle fig(5.0);
    fig.setRad(0.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getLen(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getSq(), 0.0);
}

TEST(MyCircleTest, SetRadiusNegative) {
    MyCircle fig(5.0);
    fig.setRad(-10.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 5.0);
}

TEST(MyCircleTest, SetRadiusMultiple) {
    MyCircle fig(1.0);
    fig.setRad(2.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 2.0);
    fig.setRad(3.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 3.0);
    fig.setRad(4.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 4.0);
}

// ========== ????? setLen (4 ?????) ==========
TEST(MyCircleTest, SetLengthPositive) {
    MyCircle fig(1.0);
    fig.setLen(2.0 * 3.141592653589793 * 7.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 7.0);
}

TEST(MyCircleTest, SetLengthZero) {
    MyCircle fig(5.0);
    fig.setLen(0.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getLen(), 0.0);
}

TEST(MyCircleTest, SetLengthNegative) {
    MyCircle fig(5.0);
    double oldR = fig.getRad();
    fig.setLen(-100.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), oldR);
}

TEST(MyCircleTest, SetLengthThenArea) {
    MyCircle fig(1.0);
    fig.setLen(2.0 * 3.141592653589793 * 4.0);
    EXPECT_DOUBLE_EQ(fig.getSq(), 3.141592653589793 * 16.0);
}

// ========== ????? setSq (4 ?????) ==========
TEST(MyCircleTest, SetAreaPositive) {
    MyCircle fig(1.0);
    fig.setSq(3.141592653589793 * 9.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 3.0);
}

TEST(MyCircleTest, SetAreaZero) {
    MyCircle fig(5.0);
    fig.setSq(0.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(fig.getSq(), 0.0);
}

TEST(MyCircleTest, SetAreaNegative) {
    MyCircle fig(5.0);
    double oldR = fig.getRad();
    fig.setSq(-50.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), oldR);
}

TEST(MyCircleTest, SetAreaThenLength) {
    MyCircle fig(1.0);
    fig.setSq(3.141592653589793 * 25.0);
    EXPECT_DOUBLE_EQ(fig.getLen(), 2.0 * 3.141592653589793 * 5.0);
}

// ========== ?????????? (2 ?????) ==========
TEST(MyCircleTest, CombinedOperations) {
    MyCircle fig(1.0);
    fig.setRad(2.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 2.0);
    fig.setLen(2.0 * 3.141592653589793 * 3.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 3.0);
    fig.setSq(3.141592653589793 * 4.0);
    EXPECT_DOUBLE_EQ(fig.getRad(), 2.0);
}

TEST(MyCircleTest, ConsistencyCheck) {
    MyCircle fig(5.0);
    double r1 = fig.getRad();
    double l1 = fig.getLen();
    double a1 = fig.getSq();
    fig.setLen(l1);
    EXPECT_DOUBLE_EQ(fig.getRad(), r1);
    EXPECT_DOUBLE_EQ(fig.getSq(), a1);
    fig.setSq(a1);
    EXPECT_DOUBLE_EQ(fig.getRad(), r1);
    EXPECT_DOUBLE_EQ(fig.getLen(), l1);
}

// ========== ?????? "????? ? ???????" (3 ?????) ==========
TEST(EarthRopeTest, GapPositive) {
    double gap = calcRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTest, GapExpectedValue) {
    double gap = calcRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.01);
}

TEST(EarthRopeTest, GapLessThanOne) {
    double gap = calcRopeGap();
    EXPECT_LT(gap, 1.0);
}

// ========== ?????? "???????" (8 ??????) ==========
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

TEST(PoolCostTest, TotalPositive) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    EXPECT_GT(concrete + fence, 0.0);
}

TEST(PoolCostTest, TotalExpected) {
    double concrete = 0.0, fence = 0.0;
    calcPoolCosts(concrete, fence);
    double total = concrete + fence;
    EXPECT_NEAR(total, 72256.0, 20.0);
}

TEST(PoolCostTest, ZeroPathWidth) {
    MyCircle pool(3.0);
    MyCircle same(3.0);
    double pathArea = same.getSq() - pool.getSq();
    EXPECT_NEAR(pathArea, 0.0, 1e-9);
}

TEST(PoolCostTest, DoublePrice) {
    double c1 = 0.0, f1 = 0.0;
    calcPoolCosts(c1, f1);
    MyCircle pool(3.0);
    MyCircle total(4.0);
    double pathArea = total.getSq() - pool.getSq();
    double fenceLen = total.getLen();
    double c2 = pathArea * 2000.0;
    double f2 = fenceLen * 4000.0;
    EXPECT_DOUBLE_EQ(c2, c1 * 2.0);
    EXPECT_DOUBLE_EQ(f2, f1 * 2.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
