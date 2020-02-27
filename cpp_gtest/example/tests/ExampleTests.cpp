#include "../Example.hpp"
#include <gtest/gtest.h>
#include <iostream>

class ExampleTests : public ::testing::Test
{
    virtual void SetUp() override {
        std::cout << "Setup()" << std::endl;
    };

    virtual void TearDown() override {
        std::cout << "TearDown()" << std::endl;
    };
};

TEST(ExampleTests, SumTest1)
{
    int a = 1;
    int b = 2;
    auto s = "Show this message";
    ASSERT_EQ(3, my_sum(a, b)) << "If this test fails, " << s;
    ASSERT_EQ(2, my_sum(a, b)) << "If this test fails, " << s;
}