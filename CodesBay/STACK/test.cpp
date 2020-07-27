#include "Stack.cpp"

#include <gtest/gtest.h>





TEST_F(StackTest, popTest){
	//Act
	int lastPopped = 9;
	
	//Assert
	while(lastPopped != 1)
	{
		ASSERT_EQ(s1.pop(), lastPopped--); 
	}
}


TEST_F(StackTest, sizeTest){
	//Act
	int value = s1.size();

	//Assert
	for(value; value > 0; value--)
	{
		ASSERT_NE(s1.size(), -1);
	}

}



int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
