#include "TextFixtures.cpp"

#include <gtest/gtest.h>


TEST(TestName, IncrementByfive) {
	//Arrange
	MyClass mc(100);

	//Act
	mc.Increment(5);
        int result = mc.getData();

	//Assert
	ASSERT_EQ(result, 105);

}






int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
