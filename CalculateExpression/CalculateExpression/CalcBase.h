#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

class CalcBase
{
public:
	int calc(string source);
	CalcBase();
	virtual ~CalcBase();
};

