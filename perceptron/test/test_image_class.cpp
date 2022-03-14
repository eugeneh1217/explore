#include <string>
#include <stdexcept>

#include "gtest/gtest.h"

#include "../src/image_class.h"

TEST(TestIo, TestInvalidImage)
{
    EXPECT_THROW(Image("invalid.jpg"), std::invalid_argument);
}

TEST(TestIo, TestValidImage)
{
    Image img = Image("test/square.jpg");
    EXPECT_EQ(img.width(), 76);
    EXPECT_EQ(img.height(), 68);
    EXPECT_EQ(img.channels(), 3);
    EXPECT_EQ(img.name(), "test/square.jpg");
}