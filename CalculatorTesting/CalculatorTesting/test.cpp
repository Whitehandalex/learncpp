#include "pch.h"
#include "Calculator.h"

TEST(CalculatorTests, Can_enter_string) 
{
	cout << "\nEnter the test combination \"1234 567890\":\n" << endl;
	Calculator calculator;
	string actual = calculator.getValues();
	string test = "1234 567890";
	ASSERT_EQ(actual, test);
}

TEST(CalculatorTests, isNumbers)
{
	Calculator calculator;
	string test = "1 2";
	bool isNumbers = calculator.checkValues(test);
	ASSERT_TRUE(isNumbers);
}

TEST(CalculatorTests, isNotNumbers)
{
	Calculator calculator;
	string test = "1s2";
	bool isNumbers = calculator.checkValues(test);
	ASSERT_TRUE(!isNumbers);
}

TEST(CalculatorTests, calculation_of_members)
{
	Calculator calculator;
	string test = " 145 34  65 6  35346";
	int number = 5;
	int actual = calculator.calculation(test);
	ASSERT_EQ(actual, number);
}

TEST(CalculatorTests, convertation)
{
	Calculator calculator;
	string test = "145";
	int number = 145;
	int actual = calculator.convertValueToInt(test);
	ASSERT_EQ(actual, number);
}

TEST(CalculatorTests, calc_func)
{
	Calculator calculator;
	cout << "For test, enter: 4 space 51 space 2" << endl;
	int actual = calculator.calc();
	ASSERT_EQ(actual, 57);
}





