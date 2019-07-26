#include "pch.h"
#include "gtest/gtest.h"
#include "ExtendCalc.h"
#include <string>
#include "ExtendCalcException.h"


TEST(ExtendCalcTest, arithmeticExpressionShouldBeResult) {
	ExtendCalc c;
	string source = "2+sin(90)+cos(90)";
	int actual = c.calc(source);
	int expected = 3;
	ASSERT_EQ(actual, expected);
}

TEST(ExtendCalcTest, just_sin_chekin) {
	ExtendCalc c;
	string source = "sin(90)";
	int actual = c.calc(source);
	int expected = 1;
	ASSERT_EQ(actual, expected);
}

TEST(ExtendCalcTest, just_cos_chekin) {
	ExtendCalc c;
	string source = "cos(90)";
	int actual = c.calc(source);
	int expected = 0;
	ASSERT_EQ(actual, expected);
}

TEST(ExtendCalcTest, just_ctan_chekin) {
	ExtendCalc c;
	string source = "ctan(90)";
	int actual = c.calc(source);
	int expected = 0;
	ASSERT_EQ(actual, expected);
}

TEST(ExtendCalcTest, tan90_ShouldBeException)
{
	ExtendCalc c;
	string source = "tan(90)";
	ASSERT_THROW(c.calc(source), ExtendCalcException);
}

TEST(ExtendCalcTest, ctan0_ShouldBeException)
{
	ExtendCalc c;
	string source = "ctan(0)";
	ASSERT_THROW(c.calc(source), ExtendCalcException);
}

TEST(ExtendCalcTest, arithmeticExpressionShouldBeResult2) {
	ExtendCalc c;
	string source = "2+55sin(90)+6cos(90)";
	int actual = c.calc(source);
	int expected = 57;
	ASSERT_EQ(actual, expected);
}


