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
		if (values.at(i) != ' ' && (values.at(i) < 48 || values.at(i) > 57))
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

int Calculator::calculation(string values)
{
	int quantity_of_members = 0;
	bool flag = false;
	for (int i = 0;i < values.length();i++)
	{
		if (values[i] != ' ' && flag == false)
		{
			quantity_of_members++;
			flag = true;
		}
		else if(values[i] == ' ')
		{
			flag = false;
		}
	}
	return quantity_of_members;
}

int Calculator::convertValueToInt(string value)
{
	int value_int = 0;
	for (int i = 0;i < value.size(); i++)
	{
		value_int += ((int)value.at(i) - 48)*pow(10, (value.size() - i - 1));
	}
	return value_int;
}

int Calculator::calc()
{
	int sum = 0;
	Calculator calculator;
	string values = calculator.getValues();
	while (!(calculator.checkValues(values)))
	{
		cout << "The string contains incorrect symbols, please try again:" << endl;
		values = calculator.getValues();
	}
	int counter = 0;
	string value;
	while (counter < values.length())
	{
		if (values[counter] != ' ')
		{
			while (counter < values.length() && values[counter] != ' ')
			{
				value += values[counter];
				counter++;
			}
			sum += calculator.convertValueToInt(value);
			value = "";
		}
		else
		{
			counter++;
		}
	}
	return sum;
}
