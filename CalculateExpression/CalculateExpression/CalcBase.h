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
	void dividing_or_multiplication(std::stack<char> &signs, int &last, std::stack<int> &numbers);
	int last_operations(std::stack<char> &signs, int &last, std::stack<int> &numbers);
	int calc(string source);
	void last_number_preparation(std::string &temp, std::stack<int> &numbers, std::stack<char> &signs, int &last);
	CalcBase();
	virtual ~CalcBase();
};

