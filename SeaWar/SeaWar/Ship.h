#pragma once
#include "Point.h"
class Ship
{
private:
	Point _place;
	bool _isAlive;
public:
	Ship(int x, int y);
	void fire(Point pt);
	bool getAlive()
	{
		return _isAlive;
	}
};

