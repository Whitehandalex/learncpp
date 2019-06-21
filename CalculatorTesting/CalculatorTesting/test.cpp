#include "pch.h"
#include "Calculator.h"

TEST(CalculatorTests, Can_enter_string) 
{
	cout << "Enter the test combination \"1234 567890\":" << endl;
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


