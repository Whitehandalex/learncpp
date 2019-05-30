#pragma once
class Point
{
private:
	int _x;
	int _y;
public:
	Point(int x, int y);
	bool operator ==(Point &pt);
	bool operator !=(Point &pt);
};

