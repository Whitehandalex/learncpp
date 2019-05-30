#include "pch.h"
#include <iostream>
#include "Ship.h"

using namespace std;

int main()
{
	Ship first(4,5);
	Point shoot(4,5);
	first.fire(shoot);
}
