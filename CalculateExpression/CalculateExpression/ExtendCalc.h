#pragma once
#include "CalcBase.h"
class ExtendCalc :
	public CalcBase
{
public:
	ExtendCalc();
	virtual ~ExtendCalc();
	int covertToNumber(string expression) override;
};

