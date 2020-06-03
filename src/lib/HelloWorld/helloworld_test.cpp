#include "helloworld.hpp"
#include "../gtest/gtest.h"

namespace {
    TEST(HelloWorld, True) {
        string expectedMsg = "Hello the condition is true.";

        HelloWorld hello(true);
        string msg = hello.get_message();
        ASSERT_STREQ(expectedMsg, msg);
    }

    TEST(HelloWorld, False) {
        string expectedMessage = "Hello the condition is false.";

        HelloWorld hello(false);
        string msg = hello.get_message();
        ASSERT_STREQ(expectedMsg, msg);
    }
}