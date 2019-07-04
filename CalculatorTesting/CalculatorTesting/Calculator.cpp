#include "pch.h"
#include "Calculator.h"


Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

/*string Calculator::getValues()
{
	string values;
	cout << "Enter numbers separated with space to get sum:" << endl;
	getline(cin, values);
	return values;
}*/

/*bool Calculator::checkValues(string values)
{
	bool isNumbers = false;
	if (values[0] == '/' && values[1] == '/')
	{
		int index_n = 0;
		for (int i = 3;i < values.size();i++)
		{
			if (values[i] == '\n')
			{
				index_n = i;
			}
		}
		vector<char> delimeters;
		for (int i = 0;i <= index_n;i++)
		{
			delimeters.push_back(values[i]);
		}
		if (values[2] >= '0' && values[2] <= '9')
		{
			return false;
		}
		for (int i = 3; i < values.size();i++)
		{
			if (values.at(i) != values.at(2) && (values.at(i) < '0' || values.at(i) > '9'))
			{
				isNumbers = false;
				break;
			}
			else
			{
				isNumbers = true;
			}
		}
	}
	else
	{
		for (int i = 0; i < values.size();i++)
		{
			if ((values.at(i) != ' ' && values.at(i) != ',') && (values.at(i) < '0' || values.at(i) > '9'))
			{
				isNumbers = false;
				break;
			}
			else
			{
				isNumbers = true;
			}
		}
	}
	return isNumbers;
}*/

/*int Calculator::calculation(string values)
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
}*/

int Calculator::convertValueToInt(string value)
{
	int value_int = 0;
	for (int i = 0;i < value.size(); i++)
	{
		value_int += ((int)value.at(i) - '0')*pow(10, (value.size() - i - 1));
	}
	return value_int;
}

int Calculator::calc(string source)
{
	int sum = 0;
	int counter = 0;
	vector<string> store;
	string temp = "";
	while (counter < source.size())
	{
		if (counter == 0 && source[0] == '/' && source[1] == '/')
		{
			if (source.size() > 2 && source[2] >= '0' && source[2] <= '9')
			{
				return -1;
			}
			else if (source.size() > 2)
			{
				if (source[3] >= '0' && source[3] <= '9')
				{
					for (int i = 3;i < source.size();i++)
					{
						if (source[i] == source[2])
						{
							source[i] = ' ';
						}
						else if (!(source[i] >= '0' && source[i] <= '9') && source[i] != source[2])
						{
							return -1;
						}
					}
				}
				else
				{
					for (int i = 2;source[i] != '\n';i++)
					{
						for (int j = 4;j < source.size();j++)
						{
							if (source[j] == source[i])
							{
								source[j] = ' ';
							}
						}
					}
				}
				for (int i = 0;source[i] <= '0' || source[i] >= '9';i++)
				{
					source[i] = ' ';
				}
			}
		}
		if (source[counter] >= '0' && source[counter] <= '9')
		{
			temp += source[counter];
		}
		else if ((source[counter] == ' ' || source[counter] == ',') && temp.size())
		{
			store.push_back(temp);
			temp = "";
		}
		else if(!(source[counter] >= '0' && source[counter] <= '9') && source[counter] != ' ' && source[counter] != ',')
		{
			return -1;
		}
		counter++;
	}
	if (temp.size())
	{
		store.push_back(temp);
	}
	for (string c : store)
	{
		sum += convertValueToInt(c);
	}
	return sum;
}

/* Calculator::calc()
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
}*/
