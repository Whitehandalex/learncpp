#include "pch.h"
#include "Worker.h"
#include <iostream>

Worker::Worker(int x, int y): Cell(x, y)
{}

Worker::~Worker()
{}

Cell & Worker::next_place(char step)
{
	int tempX = 0, tempY = 0;
	char step;
	cin >> step;
	switch ((int)step)
	{
	case 24: tempX = _x, tempY = _y++;
		break;
	case 25: tempX = _x, tempY = _y--;
		break; 
	case 26: tempX = _x++, tempY = _y;
		break; 
	case 27: tempX = _x--, tempY = _y;
		break; 
	}
	Cell temp(tempX, tempY);
	return temp;
}
