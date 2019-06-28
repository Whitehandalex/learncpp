#pragma once
#include <iostream>
using namespace std;

class Cell
{
protected:
	int _x;
	int _y;
public:
	Cell(int x, int y);
	virtual ~Cell();
};

