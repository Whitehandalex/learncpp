#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
const int SIZE_X = 2;
const int SIZE_Y = 2;
template <typename T>
class Matrix
{
private:
	T _data[SIZE_X][SIZE_Y];
	int currentX;
	int currentY;
public:
	Matrix():currentX(0), currentY(0), _data{}
	{}
	void add(T data)
	{
		_data[currentX][currentY] = data;
		if (currentY < (SIZE_Y-1))
		{
			currentY++;
		}
		else if (currentY == (SIZE_Y - 1) && currentX < (SIZE_X -1))
		{
			currentX++;
			currentY = 0;
		}
		else if(currentX == (SIZE_X-1) && currentY == (SIZE_Y - 1))
		{
			cout << "Matrix is FULL" << endl;
		}
	}
	void printMatrix()
	{
		for (int i = 0;i < SIZE_X;i++)
		{
			for (int j = 0;j < SIZE_Y;j++)
			{
				cout << setw(5) << _data[i][j];
			}
			cout << endl << endl;
		}
		cout << endl;
	}
	void printElement(int x, int y)
	{
		cout << _data[x][y] << endl;
	}
};

class MyType
{
private:
	int _first;
	char _second;
public:
	MyType() :_first(0), _second('0')
	{}
	MyType(int a, char b):_first(a), _second(b)
	{}
	friend ostream& operator << (ostream& s, MyType& obj)
	{
		s << obj._first << obj._second;
		return s;
	}
};

int main()
{
	Matrix<int> i;
	i.add(1);
	i.add(2);
	i.add(3);
	i.add(4);
	Matrix<double> d;
	d.add(1.11);
	d.add(2.12);
	d.add(3.13);
	d.add(4.14);
	Matrix<char> c;
	c.add('a');
	c.add('b');
	c.add('c');
	c.add('d');
	Matrix<string> str;
	str.add("abc");
	str.add("def");
	str.add("ghi");
	str.add("jkl");
	MyType my_obj1(1, 'a');
	MyType my_obj2(2, 'b');
	MyType my_obj3(3, 'c');
	MyType my_obj4(4, 'd');
	Matrix<MyType> my;
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
}
