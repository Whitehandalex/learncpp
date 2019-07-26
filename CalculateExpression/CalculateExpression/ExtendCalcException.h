#pragma once
#include "CalcException.h"
class ExtendCalcException :
	public CalcException
{
public:
	ExtendCalcException();
	virtual ~ExtendCalcException();
};

