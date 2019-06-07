#include "pch.h"
#include "DataTypes.h"
#include <iostream>

using namespace std;

DataTypes::DataTypes():_data(0)
{}

DataTypes::DataTypes(int data): _data(data)
{}


DataTypes::~DataTypes()
{
}

ostream & operator<<(ostream & s, DataTypes & d)
{
	s << d._data << " ";
	return s;
}
