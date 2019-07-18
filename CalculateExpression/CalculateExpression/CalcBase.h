#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

class CalcBase
{
private:
	double division_and_multiplication();
public:
	int calc(string source);
	CalcBase();
	virtual ~CalcBase();
};

