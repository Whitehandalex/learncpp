#include "pch.h"
#include "CalcBase.h"
#include <exception>
#include "CalcException.h"

int CalcBase::calc(string source)
{
	stack<int> numbers;
	stack<char> signs;
	string temp = "";
	int last = 0;
	for (int i = 0;i < source.size();i++)
	{
		if (source.at(i) == ' ')
		{
			source.erase(i, 1);
		}
		if (!(source.at(i) <= '9' || source.at(i) >= '0') && !(source.at(i) == '+' || source.at(i) == '-' || source.at(i) == '*' || source.at(i) == '/'))
		{
			cout << "MISSTAKE wrong symbol" << endl;
			throw CalcException();
		}
		if (source.at(i) >= '0' && source.at(i) <= '9')
		{
			temp += source.at(i);
		}
		else if (source.at(i) == '*' || source.at(i) == '/' || source.at(i) == '+' || source.at(i) == '-')
		{
			if (temp.size())
			{
				int number = 0;
				for (int i = 0;i < temp.size();i++)
				{
					number += (int)(temp.at(i) - '0') * pow(10, temp.size() - 1 - i);
				}
				numbers.push(number);
				temp = "";
			}
			else
			{
				cout << "MISSTAKE more than one signs in a row" << endl;
				throw CalcException();
			}
			if (source.at(i) == '*' || source.at(i) == '/')
			{
				if (signs.top() == '*' || signs.top() == '/')
				{
					if (signs.top() == '/')
						last = 1 / numbers.top();
					else
						last = numbers.top();
					numbers.pop();
					numbers.push(numbers.top()*last);
					signs.pop();
				}
			}
			signs.push(source.at(i));
		}
	}
	if (temp.size())
	{
		int number = 0;
		for (int i = 0;i < temp.size();i++)
		{
			number += (int)(temp.at(i) - '0') * pow(10, temp.size() - 1 - i);
		}
		numbers.push(number);
		temp = "";
	}
	if (numbers.size() == signs.size())
	{
		cout << "MISSTAKE the last symbol is sign" << endl;
		throw CalcException();
	}
	if (signs.top() == '*' || signs.top() == '/')
	{
		if (signs.top() == '/')
			last = 1 / numbers.top();
		else
			last = numbers.top();
		numbers.pop();
		int penult = numbers.top();
		numbers.pop();
		numbers.push(penult*last);
		signs.pop();
	}
	while (signs.size())
	{
		last = numbers.top();
		numbers.pop();
		if (signs.top() == '+')
		{
			numbers.top() += last;
		}
		else
		{
			numbers.top() -= last;
		}
		signs.pop();
	}
	return numbers.top();
}

CalcBase::CalcBase()
{
}


CalcBase::~CalcBase()
{
}
