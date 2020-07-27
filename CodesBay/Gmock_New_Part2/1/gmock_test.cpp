#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::Invoke;

class DatabaseConnect {
public:
	virtual bool login(std::string username, std::string password){
		std::cout<<"Original Login.."<<std::endl;
		return true;
         }
        
        virtual bool login2(std::string username, std::string password){
		return true;
         }

	virtual bool logout(std::string username){
		return true;
	}

	virtual int fetchrecord() {
		return -1;
	}
};


class MockDB : public DatabaseConnect {
public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool(std::string username));
	MOCK_METHOD2(login, bool(std::string username, std::string password));
	MOCK_METHOD2(login2, bool(std::string username, std::string password));
};

class MyDataBaseConnect {

private:
	DatabaseConnect &DbC;

public:
	MyDataBaseConnect(DatabaseConnect &_DbC) : DbC(_DbC) { }
        int Init(std::string username, std::string password) 
	{
		//int rvalue = rand() % 2;
               // if(rvalue == 0) {
			if(DbC.login(username, password) != true) {
				//if(DbC.login(username, password) != true)
					std::cout << "DB Failure" <<std::endl;
					return -1;
			}	
		
			else
			{
				std::cout <<"DB success"<<std::endl;
				return 1;
			}
		//}
		//else{
		//	return DbC.login2(username, password);
		//}
	}
	
};


/*
TEST(MyDBTest, LoginTest) {
	//Arrange
	MockDB mdb;
	MyDataBaseConnect db(mdb);
	
	
        ON_CALL(mdb, login(_,_)).WillByDefault(Return(true));	
	ON_CALL(mdb, login2(_,_)).WillByDefault(Return(true));	
	//Act
	int value = db.Init("MyLogin", "MyPassword");

	//Assert
	EXPECT_EQ(value, 1);	
}*/


TEST(MyDBTest, LoginTest) {
	//Arrange
	MockDB mdb;
	MyDataBaseConnect db(mdb);
	DatabaseConnect dcon;
	//EXPECT_CALL(mdb, login("MyLogin", "MyPassword"))
	EXPECT_CALL(mdb, login(_,_))
	.Times(AtLeast(1))
	//.WillOnce(Return(true));
	.WillOnce(Invoke(&dcon, &DatabaseConnect::login));	
	
	//Act
	int value = db.Init("MyLogin", "MyPassword");

	//Assert
	EXPECT_EQ(value, 1);	
}

/*

TEST(MyDBTest, LoginTestRepeat) {
	//Arrange
	MockDB mdb;
	MyDataBaseConnect db(mdb);
	
	//EXPECT_CALL(mdb, login("MyLogin", "MyPassword"))
	EXPECT_CALL(mdb, login(_,_))
	.Times(AtLeast(1))
	.WillRepeatedly(Return(true));	
	
	//Act
	int value = db.Init("MyLogin", "MyPassword");

	//Assert
	EXPECT_EQ(value, 1);	
}*/



/*TEST(MyDBTest, LoginFailure) {
	//Arrange
	MockDB mdb;
	MyDataBaseConnect db(mdb);
	
	//EXPECT_CALL(mdb, login("MyLogin", "MyPassword"))
	EXPECT_CALL(mdb, login(_,_))
	.Times(AtLeast(1))
	.WillOnce(Return(false));	
	
	//Act
	int value = db.Init("MyLogin", "MyPassword");

	//Assert
	EXPECT_EQ(value, -1);	
}*/


int main(int argc, char **argv)
{

	/*int main(int argc, char *argv[]) { ::testing::InitGoogleMock(&argc, argv); return RUN_ALL_TESTS(); }

        testing::InitGoogleMock(&__argc, __argv);*/
	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}


 
		
	
