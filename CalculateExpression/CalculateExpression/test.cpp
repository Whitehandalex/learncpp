#include "pch.h"
#include "CalcBase.h"
#include "CalcException.h"
#include <string>
#include "DivideByZeroException.h"

using namespace std;

TEST(CalculateExpression, PlusTwoOperandShouldBeCorrectValue) {
	CalcBase c;
	string source = "12 + 20";
	int expected = 32;
	int actual = c.calc(source);
	ASSERT_EQ(actual, expected);
  
}

TEST(CalculateExpression, MinusTwoOperandShouldBeCorrectValue) {
	CalcBase c;
	string source = "12 - 20";
	int expected = -8;
	int actual = c.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculateExpression, WrongParameterShouldBeException) {
	CalcBase c;
	string source = "20 + ";
	ASSERT_THROW(
		c.calc(source),
		CalcException);
}

TEST(CalculateExpression, ExpressionWithThreeOperandShouldBeCorrectValue) {
	CalcBase c;
	string source = "12 + 20 * 2";
	int expected = 52;
	int actual = c.calc(source);
	ASSERT_EQ(actual, expected);
}

TEST(CalculateExpression, DivideZeroShouldBeException)
{
	CalcBase c;
	string source = "12/0";
	ASSERT_THROW(c.calc(source), DivideByZeroException);
}

TEST(CalculateExpression, DivideZeroAndPLusShouldBeException)
{
	CalcBase c;
	string source = "12/0+5";
	ASSERT_THROW(c.calc(source), DivideByZeroException);
}

TEST(CalculateExpression, stringWithFunctionsShouldBeException)
{
	CalcBase c;
	string source = "2+sin(90)+cos(90)";
	ASSERT_THROW(c.calc(source), CalcException);
}
