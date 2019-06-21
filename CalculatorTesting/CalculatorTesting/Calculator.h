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
	int convertValuesToInt(string value);
	int calc(int value_1, int value_2);
};

