#pragma once
#include "pch.h"
#include "CalcException.h"
class DivideByZeroException :
	public CalcException
{
public: 
	DivideByZeroException() {}
	~DivideByZeroException() {}
};



