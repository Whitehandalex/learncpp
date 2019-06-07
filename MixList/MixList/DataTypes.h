#pragma once
#include "pch.h"
#include<iostream>

using namespace std;

class DataTypes
{
private:
	int _data;
public:
	DataTypes();
	DataTypes(int data);
	~DataTypes();
	friend ostream & operator <<(ostream & s, DataTypes & d);
};

