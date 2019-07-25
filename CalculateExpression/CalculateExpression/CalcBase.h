#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

class CalcBase
{
private:
	int division_and_multiplication_preparation(char sign, int last_number);
protected:
	virtual int covertToNumber(string expression);
public:
	int calc(string source);
	CalcBase();
	virtual ~CalcBase();
};

