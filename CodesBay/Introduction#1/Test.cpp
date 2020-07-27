#include <iostream>
#include <gtest/gtest.h>


TEST(TestName, Subtest){
	ASSERT_TRUE(1 == 1);
}

TEST(TestName_1,Subtest)
{
	ASSERT_FALSE(2 == 3);
} 


TEST(FatalAssertion, TrueFalse)
{
       ASSERT_TRUE(1 == 1);
       std::cout<<"Fatal Assertion"<<std::endl;
}

TEST(FatalAssertion, EQ)
{
       ASSERT_EQ(1, 2);
       std::cout<<"Fatal Assertion"<<std::endl;
}

TEST(NonFatalAssertion, EQ)
{
	EXPECT_EQ(1,2);
	std::cout<<"Non-Fatal Assertion"<<std::endl;
}


TEST(NonFatalAssertion, EQ_1)
{
	EXPECT_EQ(1,1);
	std::cout<<"Non-Fatal Assertion"<<std::endl;
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

