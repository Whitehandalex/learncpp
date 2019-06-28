#pragma once
#include "Cell.h"

class Worker :
	public Cell
{
public:
	Worker(int x, int y);
	~Worker();
	Cell & next_place(char step);
};

