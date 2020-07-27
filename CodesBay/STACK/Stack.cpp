#include <iostream>
#include <vector>
#include <gtest/gtest.h>

class Stack {

	std::vector<int> vstack{};
public:
	void push(int value){vstack.push_back(value);}

	int pop() {

	if (vstack.size() > 0)
	{
		int pValue = vstack.back();
   		vstack.pop_back();
		return pValue;
	}
	else
	{
		return -1;
	}
     }

	int size()
	{
		return vstack.size();
	}

	
};


struct StackTest : public testing::Test {
	
	Stack s1;
	void SetUp() 
	{
		int val[] = {1,2,3,4,5,6,7,8,9};
		for(auto &value : val)
		{
			s1.push(value);
		}	
        }

	void TearDown() {}	
};

