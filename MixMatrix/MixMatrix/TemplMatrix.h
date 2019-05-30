#pragma once
#include <iostream>
#include "pch.h"

using namespace std;

extern const int SIZE_X;
extern const int SIZE_Y;

template <typename T>
class TemplMatrix
{
private:
	T _data[SIZE_X][SIZE_Y];
	int currentX;
	int currentY;
public:
	TemplMatrix();
	void add(T data);
	void printMatrix();
	void printElement(int x, int y);
};

template<typename T>
inline TemplMatrix<T>::TemplMatrix() : currentX(0), currentY(0), _data{}
{}

template<typename T>
inline void TemplMatrix<T>::add(T data)
{
	_data[currentX][currentY] = data;
	if (currentY < (SIZE_Y - 1))
	{
		currentY++;
	}
	else if (currentY == (SIZE_Y - 1) && currentX < (SIZE_X - 1))
	{
		currentX++;
		currentY = 0;
	}
	else if (currentX == (SIZE_X - 1) && currentY == (SIZE_Y - 1))
	{
		cout << "Matrix is FULL" << endl;
	}

}

template<typename T>
inline void TemplMatrix<T>::printMatrix()
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

template<typename T>
inline void TemplMatrix<T>::printElement(int x, int y)
{
	cout << _data[x][y] << endl;
}


