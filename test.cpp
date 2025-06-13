#include "headers.h"
#include<gtest/gtest.h>

TEST(sample_test, first_sum){
    EXPECT_EQ(sum(10,10),20);
    EXPECT_EQ(sum(2,1),3);
    EXPECT_EQ(sum(-1,-2),0);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}