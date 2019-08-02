#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

class CalcBase
{
private:
	int division_and_multiplication_preparation(char sign, int last_number);
	bool is_sign(char c);
	bool is_priority_sign(char c);
protected:
	virtual int covertToNumber(string expression);
public:
	int calc(string source);
	CalcBase();
	virtual ~CalcBase();
};

