#pragma once
#include <iostream>
using namespace std;
class UserType
{
private:
	int _first;
	char _second;
public:
	UserType(); 
	UserType(int a, char b); 
	friend ostream& operator << (ostream& s, UserType& obj);
};

