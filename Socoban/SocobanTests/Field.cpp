#include "pch.h"
#include "Field.h"

Field::Field()
{}

Field::~Field()
{}

void Field::addCell(Cell * c)
{
	_field.push_back(c);
}

void Field::checkCell(Cell * next)
{

}

