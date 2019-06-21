#include "pch.h"
#include "Calculator.h"

TEST(CalculatorTests, Can_enter_string) 
{
	Calculator calculator;
	string actual = calculator.getValues();
	string test = "1 2";
	ASSERT_EQ(actual, test);
}

TEST(CalculatorTests, isStringEmpty)
{
	Calculator calculator;
	string actual = calculator.getValues();
	ASSERT_EQ(actual.size(), 0);
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


