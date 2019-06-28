#include "pch.h"
#include "Cell.h"

TEST(CellTests, CorrectInitalize)
{
	Cell c(2, 3);
	int actual = 0;
	actualX = c.getX();
	ASSERT_EQ(actual, 2);
}

