#include "pch.h"
#include "Ship.h"


Ship::Ship(int x, int y):_place(x, y), _isAlive(true)
{
}

void Ship::fire(Point pt)
{
	if (pt==_place) //pt.operator==(_place)
	{
		_isAlive = false;
	}
}


