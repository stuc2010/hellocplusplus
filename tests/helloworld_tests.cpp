#include <helloworld.hpp>
#include <gtest/gtest.h>

TEST(HelloWorld, True) {
    EXPECT_EQ(true, false);
};

TEST(HelloWorld, False) {
    EXPECT_EQ(false, true);
};