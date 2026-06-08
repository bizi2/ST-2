// Copyright 2025 UNN-CS
// Nazyrov A.A.

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

// ========== ??????????? ? ??????? ??????? ==========

TEST(MyCircleTest, ConstructorWithPositiveRadius) {
    MyCircle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 5.0);
}

TEST(MyCircleTest, ConstructorWithZero) {
    MyCircle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(c.getLen(), 0.0);
    EXPECT_DOUBLE_EQ(c.getSq(), 0.0);
}

TEST(MyCircleTest, ConstructorWithNegativeValue) {
    MyCircle c(-5.0);
    EXPECT_DOUBLE_EQ(c.getRad(), -5.0);
}

TEST(MyCircleTest, CircumferenceFromRadius) {
    MyCircle c(5.0);
    double expected = 2.0 * 3.141592653589793 * 5.0;
    EXPECT_DOUBLE_EQ(c.getLen(), expected);
}

TEST(MyCircleTest, AreaFromRadius) {
    MyCircle c(5.0);
    double expected = 3.141592653589793 * 25.0;
    EXPECT_DOUBLE_EQ(c.getSq(), expected);
}

TEST(MyCircleTest, LargeRadius) {
    MyCircle c(10000.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 10000.0);
    EXPECT_DOUBLE_EQ(c.getLen(), 2.0 * 3.141592653589793 * 10000.0);
}

TEST(MyCircleTest, SmallRadius) {
    MyCircle c(0.001);
    EXPECT_DOUBLE_EQ(c.getRad(), 0.001);
}

// ========== ????? setRad ==========

TEST(MyCircleTest, SetRadiusPositive) {
    MyCircle c(1.0);
    c.setRad(10.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 10.0);
    EXPECT_DOUBLE_EQ(c.getLen(), 2.0 * 3.141592653589793 * 10.0);
    EXPECT_DOUBLE_EQ(c.getSq(), 3.141592653589793 * 100.0);
}

TEST(MyCircleTest, SetRadiusZero) {
    MyCircle c(5.0);
    c.setRad(0.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(c.getLen(), 0.0);
    EXPECT_DOUBLE_EQ(c.getSq(), 0.0);
}

TEST(MyCircleTest, SetRadiusNegative) {
    MyCircle c(5.0);
    c.setRad(-10.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 5.0);
}

TEST(MyCircleTest, SetRadiusMultipleTimes) {
    MyCircle c(1.0);
    c.setRad(2.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 2.0);
    c.setRad(3.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 3.0);
    c.setRad(4.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 4.0);
}

// ========== ????? setLen ==========

TEST(MyCircleTest, SetLengthPositive) {
    MyCircle c(1.0);
    c.setLen(2.0 * 3.141592653589793 * 7.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 7.0);
}

TEST(MyCircleTest, SetLengthZero) {
    MyCircle c(5.0);
    c.setLen(0.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(c.getLen(), 0.0);
}

TEST(MyCircleTest, SetLengthNegative) {
    MyCircle c(5.0);
    double oldRad = c.getRad();
    c.setLen(-100.0);
    EXPECT_DOUBLE_EQ(c.getRad(), oldRad);
}

TEST(MyCircleTest, SetLengthThenCheckArea) {
    MyCircle c(1.0);
    c.setLen(2.0 * 3.141592653589793 * 4.0);
    EXPECT_DOUBLE_EQ(c.getSq(), 3.141592653589793 * 16.0);
}

// ========== ????? setSq ==========

TEST(MyCircleTest, SetAreaPositive) {
    MyCircle c(1.0);
    c.setSq(3.141592653589793 * 9.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 3.0);
}

TEST(MyCircleTest, SetAreaZero) {
    MyCircle c(5.0);
    c.setSq(0.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 0.0);
    EXPECT_DOUBLE_EQ(c.getSq(), 0.0);
}

TEST(MyCircleTest, SetAreaNegative) {
    MyCircle c(5.0);
    double oldRad = c.getRad();
    c.setSq(-50.0);
    EXPECT_DOUBLE_EQ(c.getRad(), oldRad);
}

TEST(MyCircleTest, SetAreaThenCheckLength) {
    MyCircle c(1.0);
    c.setSq(3.141592653589793 * 25.0);
    EXPECT_DOUBLE_EQ(c.getLen(), 2.0 * 3.141592653589793 * 5.0);
}

// ========== ??????????????? ????? ==========

TEST(MyCircleTest, SetRadThenSetLenThenSetSq) {
    MyCircle c(1.0);
    c.setRad(2.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 2.0);
    c.setLen(2.0 * 3.141592653589793 * 3.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 3.0);
    c.setSq(3.141592653589793 * 4.0);
    EXPECT_DOUBLE_EQ(c.getRad(), 2.0);
}

TEST(MyCircleTest, ConsistencyCheckAfterMultipleOperations) {
    MyCircle c(5.0);
    double r1 = c.getRad();
    double l1 = c.getLen();
    double a1 = c.getSq();
    
    c.setLen(l1);
    EXPECT_DOUBLE_EQ(c.getRad(), r1);
    EXPECT_DOUBLE_EQ(c.getSq(), a1);
    
    c.setSq(a1);
    EXPECT_DOUBLE_EQ(c.getRad(), r1);
    EXPECT_DOUBLE_EQ(c.getLen(), l1);
}

// ========== ?????? "????? ? ???????" ==========

TEST(EarthRopeTest, GapIsPositiveNumber) {
    double gap = earthRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTest, GapAboutFifteenCm) {
    double gap = earthRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.01);
}

TEST(EarthRopeTest, GapLessThanOneMeter) {
    double gap = earthRopeGap();
    EXPECT_LT(gap, 1.0);
}

TEST(EarthRopeTest, GapReasonableValue) {
    double gap = earthRopeGap();
    EXPECT_GT(gap, 0.1);
    EXPECT_LT(gap, 0.2);
}

// ========== ?????? "???????" ==========

TEST(PoolCostTest, ConcreteCostIsPositive) {
    double concrete = 0.0, fence = 0.0;
    poolCostCalc(concrete, fence);
    EXPECT_GT(concrete, 0.0);
}

TEST(PoolCostTest, FenceCostIsPositive) {
    double concrete = 0.0, fence = 0.0;
    poolCostCalc(concrete, fence);
    EXPECT_GT(fence, 0.0);
}

TEST(PoolCostTest, ConcreteCostExpectedValue) {
    double concrete = 0.0, fence = 0.0;
    poolCostCalc(concrete, fence);
    EXPECT_NEAR(concrete, 21991.0, 10.0);
}

TEST(PoolCostTest, FenceCostExpectedValue) {
    double concrete = 0.0, fence = 0.0;
    poolCostCalc(concrete, fence);
    EXPECT_NEAR(fence, 50265.0, 10.0);
}

TEST(PoolCostTest, TotalCostIsPositive) {
    double concrete = 0.0, fence = 0.0;
    poolCostCalc(concrete, fence);
    EXPECT_GT(concrete + fence, 0.0);
}

TEST(PoolCostTest, TotalCostExpected) {
    double concrete = 0.0, fence = 0.0;
    poolCostCalc(concrete, fence);
    double total = concrete + fence;
    EXPECT_NEAR(total, 72256.0, 20.0);
}

TEST(PoolCostTest, ZeroPathWidthCost) {
    MyCircle pool(3.0);
    MyCircle withPath(3.0);
    double pathArea = withPath.getSq() - pool.getSq();
    EXPECT_NEAR(pathArea, 0.0, 1e-9);
}

TEST(PoolCostTest, DoublePriceComparison) {
    double c1 = 0.0, f1 = 0.0;
    double c2 = 0.0, f2 = 0.0;
    poolCostCalc(c1, f1);
    
    MyCircle pool(3.0);
    MyCircle total(4.0);
    double pathArea = total.getSq() - pool.getSq();
    double fenceLen = total.getLen();
    
    c2 = pathArea * 2000.0;
    f2 = fenceLen * 4000.0;
    
    EXPECT_DOUBLE_EQ(c2, c1 * 2.0);
    EXPECT_DOUBLE_EQ(f2, f1 * 2.0);
}

TEST(PoolCostTest, DifferentPoolRadius) {
    double c1 = 0.0, f1 = 0.0;
    double c2 = 0.0, f2 = 0.0;
    poolCostCalc(c1, f1);
    
    MyCircle pool(5.0);
    MyCircle total(6.0);
    double pathArea = total.getSq() - pool.getSq();
    double fenceLen = total.getLen();
    
    c2 = pathArea * 1000.0;
    f2 = fenceLen * 2000.0;
    
    EXPECT_NEAR(c2, 34557.5, 10.0);
    EXPECT_NEAR(f2, 75398.2, 10.0);
}

TEST(PoolCostTest, WiderPath) {
    double c1 = 0.0, f1 = 0.0;
    poolCostCalc(c1, f1);
    
    MyCircle pool(3.0);
    MyCircle total(5.0);
    double pathArea = total.getSq() - pool.getSq();
    double fenceLen = total.getLen();
    
    double concrete2 = pathArea * 1000.0;
    double fence2 = fenceLen * 2000.0;
    
    EXPECT_GT(concrete2, c1);
    EXPECT_GT(fence2, f1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

