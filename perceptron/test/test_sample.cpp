#include "gtest/gtest.h"
#include "../src/sample.cpp"

TEST(TestSample, TestTriple)
{
    EXPECT_EQ(triple(3), 9);
}