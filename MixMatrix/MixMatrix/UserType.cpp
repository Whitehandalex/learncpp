#include "pch.h"
#include "UserType.h"

UserType::UserType() : _first(0), _second('0')
{}

UserType::UserType(int a, char b) : _first(a), _second(b)
{}

ostream & operator<<(ostream & s, UserType & obj)
{
	s << obj._first << obj._second;
	return s;
}
