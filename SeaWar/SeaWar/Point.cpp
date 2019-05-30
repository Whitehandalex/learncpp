#include "pch.h"
#include "Point.h"

Point::Point(int x, int y)
{
	_x = x;
	_y = y;
}

bool Point::operator==(Point & pt)
{
	return (_x==pt._x && _y==pt._y);
}

bool Point::operator!=(Point & pt)
{
	return (_x!=pt._x || _y!=pt._y);
}

