#pragma once
#include "CalcException.h"
class DivideByZeroException :
	public CalcException
{
public: 
	DivideByZeroException() {}
	~DivideByZeroException() {}
};



