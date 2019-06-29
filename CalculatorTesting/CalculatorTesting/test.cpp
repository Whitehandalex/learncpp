#include "pch.h"
#include "Calculator.h"
#include "test.h"

/* TEST(CalculatorTests, Can_enter_string) 
{
	cout << "\nEnter the test combination \"1234 567890\":\n" << endl;
	Calculator calculator;
	string actual = calculator.getValues();
	string test = "1234 567890";
	ASSERT_EQ(actual, test);
}
*/
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
/*
TEST(CalculatorTests, calc_func)
{
	Calculator calculator;
	cout << "For test, enter: 4 space 51 space 2" << endl;
	int actual = calculator.calc();
	ASSERT_EQ(actual, 57);
}
*/
TEST(CalculatorTests, calc_func)
{
	Calculator calculator;
	string source = "125  10";
	int expected = 135;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, checkString)
{
	Calculator calculator;
	string source = "124 r 10 ";
	int expected = -1;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, checkSpaces_1)
{
	Calculator calculator;
	string source = "  124 r 10  ";
	int expected = -1;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, checkSpaces_2)
{
	Calculator calculator;
	string source = "  125  10 ";
	int expected = 135;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, with_commas)
{
	Calculator calculator;
	string source = " 123,5, 56 ";
	int expected = 184;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, NewDelimeter_1)
{
	Calculator calculator;
	string source = "//#12#22#1";
	int expected = 35;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, NewDelimeter_misstake)
{
	Calculator calculator;
	string source = "//#12+22#1";
	int expected = -1;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, NewDelimeter_2)
{
	Calculator calculator;
	string source = "//@12@22@1";
	int expected = 35;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, NewDelimeter_misstake_space_comma)
{
	Calculator calculator;
	string source = "//#12, 22#1";
	int expected = -1;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, NewDelimeter_misstake_number)
{
	Calculator calculator;
	string source = "//91292291";
	int expected = -1;
	int actual = calculator.calc(source); 
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, NewDelimeter_misstake_number_2)
{
	Calculator calculator;
	string source = "//81282281";
	int expected = -1;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, FewDelimetersShouldBeOk)
{
	Calculator calculator;
	string source = "//#@\n20#30@1";
	int expected = 51;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculatorTests, FewDelimeters_n)
{
	Calculator calculator;
	string source = "//#\n\n20\n30#1";
	int expected = -1;
	int actual = calculator.calc(source);
	ASSERT_EQ(actual, expected);
}


