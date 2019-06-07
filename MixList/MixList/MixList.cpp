#include "pch.h"
#include <iostream>
#include "List.h"
#include "MixList.h"
#include "DataTypes.h"

using namespace std;

int main()
{
	/*List i;
	i.push_front(1);
	i.push_front(2);
	i.push_front(3);
	i.push_back(0);
	i.pop_front();
	i.insert(2, 24);
	i.pop_back();
	i.print();
	i.removeAt(2);
	i.print();
	MixList<int> I;
	I.push_front(1);
	I.push_front(2);
	I.push_front(3);
	I.push_front(4);
	I.print();
	MixList<char> c;
	c.push_front('a');
	c.push_front('b');
	c.push_front('c');
	c.push_back('d');
	c.push_back('e');
	c.print();*/
	MixList<DataTypes> d;
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	d.push_front(4);
	d.print();
}
