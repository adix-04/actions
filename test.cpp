#include "headers.h"
#include<gtest/gtest.h>

TEST(sample_test, first_sum){
    EXPECT_EQ(sum(10,10),20);
    EXPECT_EQ(sum(2,1),3);
    EXPECT_EQ(sum(-1,-2),0);
}
TEST(sample_test2, diff_test){
    EXPECT_EQ(diff(20,10),11);
    EXPECT_EQ(diff(13,2),11);
    EXPECT_EQ(diff(22,10),12);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}