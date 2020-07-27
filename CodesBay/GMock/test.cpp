#include "gmock_test.cpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


class MockDB : public DatabaseConnect {
public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool(std::string username));
	MOCK_METHOD2(login, bool(std::string username, std::string password));
};

TEST(MyDBTest, LoginTest) {
	//Arrange
	MockDB mdb;
	MyDataBaseConnect db(mdb);
	
	EXPECT_CALL(mdb, login("MyLogin", "MyPassword"))
	.Times(1)
	.WillOnce(Return(true));	
	
	//Act
	int value = db.Init("MyLogin", "MyPassword");

	//Assert
	EXPECT_EQ(value, 1);	
}

int main(int argc, char **argv)
{

	/*int main(int argc, char *argv[]) { ::testing::InitGoogleMock(&argc, argv); return RUN_ALL_TESTS(); }

        testing::InitGoogleMock(&__argc, __argv);*/
	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}

