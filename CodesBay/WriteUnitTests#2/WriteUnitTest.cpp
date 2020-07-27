#include <iostream>

class MyClass {
private:
	std::string id;
public:
	MyClass(std::string _id) : id(_id){}
	std::string getID(){return id;}
};
