#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "TemplMatrix.h"
#include "UserType.h"

using namespace std;
const int SIZE_X = 2;
const int SIZE_Y = 2;

int main()
{
	TemplMatrix<int> i;
	i.add(1);
	i.add(2);
	i.add(3);
	i.add(4);
	TemplMatrix<double> d;
	d.add(1.11);
	d.add(2.12);
	d.add(3.13);
	d.add(4.14);
	TemplMatrix<char> c;
	c.add('a');
	c.add('b');
	c.add('c');
	c.add('d');
	TemplMatrix<string> str;
	str.add("abc");
	str.add("def");
	str.add("ghi");
	str.add("jkl");
	UserType my_obj1(1, 'a');
	UserType my_obj2(2, 'b');
	UserType my_obj3(3, 'c');
	UserType my_obj4(4, 'd');
	TemplMatrix<UserType> my;
	my.add(my_obj1);
	my.add(my_obj2);
	my.add(my_obj3);
	my.add(my_obj4);
	i.printMatrix();
	d.printMatrix();
	c.printMatrix();
	str.printMatrix();
	my.printMatrix();
	i.printElement(0, 0);
	d.printElement(0, 0);
	c.printElement(0, 0);
	str.printElement(0, 0);
	my.printElement(0, 0);
	TemplMatrix<int, 3, 3> i2;
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.add(1);
	i2.printMatrix();
}
