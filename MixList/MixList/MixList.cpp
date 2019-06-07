#include "pch.h"
#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List i;
	i.push_front(1);
	i.push_front(2);
	i.push_front(3);
	i.push_front(4);
	i.push_front(5);
	i.push_back(0);
	i.print();
	i.pop_front();
	i.print();
	i.insert(2, 24);
	i.print();
	i.pop_back();
	i.print();
	i.removeAt(2);
	i.print();
}
