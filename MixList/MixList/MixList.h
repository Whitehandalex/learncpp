#pragma once
#include "pch.h"
#include <iostream>

using namespace std;

template <typename T>
class MixList
{
private:
	template <typename T>
	class MixBlock
	{
	public:
		T _data;
		MixBlock<T>* _next;
	};
	MixBlock<T>* _first;
	int _size;
public:
	MixList<T>();
	~MixList<T>();
	void push_front(T data);
	void push_back(T data);
	void print();
	int get_size();
	void pop_front();
	void clear();
};

template<typename T>
inline MixList<T>::MixList():_first(nullptr), _size(0)
{}

template<typename T>
inline MixList<T>::~MixList()
{
	void clear();
}

template<typename T>
inline void MixList<T>::push_front(T data)
{
	MixBlock<T>* newLast = new MixBlock<T>;
	newLast->_data = data;
	newLast->_next = _first;
	_first = newLast;
	_size++;
}

template<typename T>
inline void MixList<T>::push_back(T data)
{
	MixBlock<T>* newLast = new MixBlock<T>;
	newLast->_data = data;
	newLast->_next = nullptr;
	MixBlock<T>* last = _first;
	while (last->_next)
	{
		last = last->_next;
	}
	last->_next = newLast;
	_size++;
}

template<typename T>
inline void MixList<T>::print()
{
	MixBlock<T>* current = _first;
	while (current)
	{
		cout << current->_data << " ";
		current = current->_next;
	}
	cout << endl;
}

template<typename T>
inline int MixList<T>::get_size()
{
	return _size;
}

template<typename T>
inline void MixList<T>::pop_front()
{
	MixBlock<T>* temp = _first;
	_first = _first->_next;
	delete temp;
	_size--;
}

template<typename T>
inline void MixList<T>::clear()
{
	while (_first)
	{
		pop_front();
	}
}
