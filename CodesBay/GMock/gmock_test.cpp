#include <iostream>
#include <string>
#include <vector>


class DatabaseConnect {
public:
	virtual bool login(std::string username, std::string password){
		return true;
         }

	virtual bool logout(std::string username){
		return true;
	}

	virtual int fetchrecord() {
		return -1;
	}
};


class MyDataBaseConnect {

private:
	DatabaseConnect &DbC;

public:
	MyDataBaseConnect(DatabaseConnect &_DbC) : DbC(_DbC) { }
        int Init(std::string username, std::string password) {
		if(DbC.login(username, password) != true) {
			std::cout << "DB Failure" <<std::endl;
			return -1;
		}
		else
		{
			std::cout <<"DB success"<<std::endl;
			return 1;
		}
	}
}; 
		
	
