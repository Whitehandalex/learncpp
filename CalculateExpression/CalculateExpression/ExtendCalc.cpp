#include "pch.h"
#include "ExtendCalc.h"
#include "ExtendCalcException.h"
#include <cmath>

constexpr auto PI = 3.14159265359;

ExtendCalc::ExtendCalc()
{
}


ExtendCalc::~ExtendCalc()
{
}

int ExtendCalc::covertToNumber(string expression)
{
	string function = "";
	string multiplier = "";
	int factor = 1;
	float meaning = 0;
	int result = 0;
	for (int i = 0;i < expression.size();i++)
	{
		if (expression.at(i) >= '0' && expression.at(i) <= '9')
		{
			while (i < expression.size() && expression.at(i) >= '0' && expression.at(i) <= '9')
			{
				multiplier += expression.at(i);
				i++;
			}
			factor = 0;
			for (int j = 0;j < multiplier.size();j++)
			{
				factor += (int)(multiplier.at(j) - '0') * (pow(10, multiplier.size() - 1 - j));
			}
			if (i == expression.size())
			{
				return factor;
			}
		}
		if (expression.at(i) >= 'a' && expression.at(i) <= 'z')
		{
			while (i < expression.size() && expression.at(i) >= 'a' && expression.at(i) <= 'z')
			{
				function += expression.at(i);
				i++;
			}
			if(function!="sin" && function != "cos" && function != "tan" && function != "ctan")
			{
				throw ExtendCalcException();
			}
			if (expression.at(i) == '(')
			{
				i++;
				if (expression.at(i) >= '0' && expression.at(i) <= '9')
				{
					string temp_meaning = "";
					while (i < expression.size() && expression.at(i) >= '0' && expression.at(i) <= '9')
					{
						temp_meaning += expression.at(i);
						i++;
					}
					for (int j = 0;j < temp_meaning.size();j++)
					{
						meaning += (int)(temp_meaning.at(j) - '0') * (pow(10, temp_meaning.size() - 1 - j));
					}
					meaning = meaning * PI / 180;
				}
			}
		}
		if (expression.back() == ')')
		{
			if (function == "sin")
			{
				result = factor * sin(meaning);
			}
			else if (function == "cos")
			{
				result = factor * cos(meaning);
			}
			else if (function == "tan")
			{
				if(cos(meaning==0))
				{
					throw ExtendCalcException();
				}
				result = factor * sin(meaning)/cos(meaning);
			}
			else if (function == "ctan")
			{
				if (sin(meaning) == 0)
				{
					throw ExtendCalcException();
				}
				result = factor * cos(meaning)/sin(meaning);
			}
		}
		else
		{
			throw ExtendCalcException();
		}
	}
	return result;
}

