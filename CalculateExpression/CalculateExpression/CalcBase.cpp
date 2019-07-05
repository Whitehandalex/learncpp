#include "pch.h"
#include "CalcBase.h"
#include <exception>
#include "CalcException.h"

int CalcBase::calc(string source)
{
	stack<int> numbers;
	stack<char> sings;
	for (int i = 0;i < source.size();i++)
	{ 
		string temp = "";
		if (source.at(i) <= '9' && source.at(i) >= '0')
		{
			temp += source.at(i);
		}
		else if (temp.size() && (source.at(i) == ' ' || source.at(i) == '+' || source.at(i) == '-' || source.at(i) == '*' || source.at(i) == '/'))
		{
			int number = 0;
			for (int i = 0;i < temp.size();i++)
			{
				number += (temp.at(i) - '0')*pow(10, (temp.size() - 1 - i));
				numbers.push(number);
				temp = "";
			}
			if (source.at(i) != ' ')
			{
				if (sings.empty())
				{
					if (source.at(i) == '+' || source.at(i) == '-')
					{
						sings.push(source.at(i));
					}
					else
					{

					}
				}
				else
				{
					sings.push(source.at(i));
				}
			}
		}

	}
	if ()
	{
		cout << "MISSTAKE" << endl;
		throw CalcException();
	}
}

CalcBase::CalcBase()
{
}


CalcBase::~CalcBase()
{
}
