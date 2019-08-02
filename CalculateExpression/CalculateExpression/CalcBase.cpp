#include "pch.h"
#include "CalcBase.h"
#include <exception>
#include "CalcException.h"
#include "DivideByZeroException.h"
#include "ExtendCalc.h"

int CalcBase::division_and_multiplication_preparation(char sign, int last_number)
{
	int last = 0;
	if (sign == '/')
	{
		if (last_number == 0)
		{
			throw DivideByZeroException();
		}
		last = 1 / last_number;
	}
	else
	{
		last = last_number;
	}
	return last;
}

bool CalcBase::is_sign(char c)
{
	return (c == '*' || c == '/' || c == '+' || c == '-');
}

bool CalcBase::is_priority_sign(char c)
{
	return (c == '*' || c == '/');
}

int CalcBase::covertToNumber(string expression)
{
	int number = 0;
	for (int i = 0;i < expression.size();i++)
	{
		if (!(expression.at(i) <= '9' && expression.at(i) >= '0') && !(expression.at(i) == '+' || expression.at(i) == '-' || expression.at(i) == '*' || expression.at(i) == '/'))
		{
			throw CalcException();
		}
		number+= (int)(expression.at(i) - '0') * pow(10, expression.size() - 1 - i);
	}
	return number;
}

void CalcBase::dividing_or_multiplication(std::stack<char> &signs, int &last, std::stack<int> &numbers)
{
	// операции деления или умножения
	if (!(signs.empty()) && is_priority_sign(signs.top()))
	{
		last = division_and_multiplication_preparation(signs.top(), numbers.top());
		if (numbers.size())
		{
			numbers.pop();
			numbers.push(numbers.top()*last);
			signs.pop();
		}
	}
}

int CalcBase::last_operations(std::stack<char> &signs, int &last, std::stack<int> &numbers)
{
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
			continue;
		}
		if (!is_sign(source.at(i)))
		{
			temp += source.at(i);
		}
		else if (is_sign(source.at(i)) && temp.size())
		{
			numbers.push(covertToNumber(temp));
			temp = "";
			dividing_or_multiplication(signs, last, numbers);
			signs.push(source.at(i));
		}
		else
		{
			throw CalcException();
		}
	}
	last_number_preparation(temp, numbers, signs, last);
	return last_operations(signs, last, numbers);
}

void CalcBase::last_number_preparation(std::string &temp, std::stack<int> &numbers, std::stack<char> &signs, int &last)
{
	if (temp.size())
	{
		numbers.push(covertToNumber(temp));
		temp = "";
	}
	if (numbers.size() == signs.size())
	{
		throw CalcException();
	}
	if (!(signs.empty()) && is_priority_sign(signs.top()))
	{
		last = division_and_multiplication_preparation(signs.top(), numbers.top());
		numbers.pop();
		int penult = numbers.top();
		numbers.pop();
		numbers.push(penult*last);
		signs.pop();
	}
}

CalcBase::CalcBase()
{
}


CalcBase::~CalcBase()
{
}
