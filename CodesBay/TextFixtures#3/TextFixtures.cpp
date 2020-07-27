#include <iostream>
#include <vector>
#include <gtest/gtest.h>
class MyClass {
private:
	int basevalue{0};
public:
	MyClass(int _bv) : basevalue(_bv){};

	void Increment(int value){
	basevalue += value;
	}

	int getData(){return basevalue;}
};


struct MyClassTest : public testing::Test {

	MyClass *mcObject;
        void SetUp() { mcObject = new MyClass(100);}
        void TearDown() { delete mcObject; }
	
};


