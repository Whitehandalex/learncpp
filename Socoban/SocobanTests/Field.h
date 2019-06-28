#pragma once
#include "Cell.h"
#include "Worker.h"
#include "Box.h"
#include "Border.h"
#include "FinPlace.h"
#include <vector>

class Field
{
private:
	vector<Cell*> _field;
public:
	Field();
	~Field();
	void addCell(Cell* c);
	void checkCell(Cell* next);
};

