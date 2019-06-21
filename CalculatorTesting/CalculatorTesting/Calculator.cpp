#include "pch.h"
#include "Calculator.h"


Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

string Calculator::getValues()
{
	string values;
	cout << "Enter numbers separated with space to get sum:" << endl;
	getline(cin, values);
	return values;
}

bool Calculator::checkValues(string values)
{
	bool isNumbers = false;
	for (int i = 0; i < values.size();i++)
	{
		if (values.at(i) != ' ' && (values.at(i) < 47 || values.at(i) > 58))
		{
			isNumbers = false;
			break;
		}
		else
		{
			isNumbers = true;
		}
	}
	return isNumbers;
}

int Calculator::convertValuesToInt(string value)
{
	return 0;
}

int Calculator::calc(int value_1, int value_2)
{
	return 0;
}
