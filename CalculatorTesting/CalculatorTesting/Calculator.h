#pragma once
#include <string>

using namespace std;

class Calculator
{
public:
	Calculator();
	~Calculator();
	string getValues();
	bool checkValues(string values);
	int calculation(string values);
	int convertValueToInt(string value);
	int calc();
};

