#include <string>
#include <stdexcept>

#include "gtest/gtest.h"

#include "../src/io.h"

TEST(TestIo, TestInvalidImage)
{
    EXPECT_THROW(Image("invalid.jpg"), std::invalid_argument);
}