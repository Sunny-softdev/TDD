#include "WriteUnitTest.cpp"

#include <gtest/gtest.h>


TEST(TestName, incrementByFive)
{
  //Arrange
   int value = 100;
   int increment = 5;

  //Act
   value += increment;

  //ASSERT

   EXPECT_EQ(value, 105);
}

TEST(TestName, incrementByTen)
{
  //Arrange
   int value = 100;
   int increment = 10;

  //Act
   value += increment;

  //ASSERT

   EXPECT_EQ(value, 110);
}

TEST(MyClassTest, subtest){

	//Arrange
	MyClass name("ID");

	//Act
	std::string value = name.getID();

	//Assert
	ASSERT_STREQ(value.c_str(), "ID");
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
