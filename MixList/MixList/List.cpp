#include "pch.h"
#include "List.h"
#include <iostream>

using namespace std;

List::List():_first(nullptr), _size(0)
{}


List::~List()
{
	cout << "~ctor" << endl;
	clear();
}

void List::push_front(int data)
{
	_size++;
	Block* newBlock = new Block;
	newBlock->_data = data;
	newBlock->_next = _first;
	_first = newBlock;
}

void List::push_back(int data)
{
	_size++;
	Block* newLast = new Block;
	newLast->_data = data;
	newLast->_next = nullptr;
	Block* current = _first;
	while(true)
	{
		current = current->_next;
		if (!current->_next)
		{
			current->_next = newLast;
			break;
		}
	}
}

void List::print()
{
	Block* current = _first;
	while (current)
	{
		cout << current->_data << " ";
		current = current->_next;
	}
	cout << endl;
}

int List::get_size()
{
	return _size;
}

int & List::operator[](int index)
{
	if (_size - index > 0)
	{
		Block* current = _first;
		int counter = 0;
		while (index - counter)
		{
			counter++;
			current = current->_next;
		}
		return current->_data;
	}
	else
	{
		cout << "The List don't have as many elements, \ntry to use index with less value" << endl;
		exit(0);
	}
}

void List::clear()
{
	while (_size)
	{
		pop_front();
		cout << "del ";
	}
}

void List::pop_front()
{
	Block* temp = _first;
	_first = temp->_next;
	delete temp;
	_size--;
}

void List::pop_back()
{
	Block* last = _first;
	int counter = 0;
	while (last->_next)
	{
		last = last->_next;
		counter++;
	}
	if (!counter)
	{
		delete _first;
	}
	else
	{
		Block* newLast = _first;
		while (true)
		{
			if (counter == 1)
			{
				delete last;
				newLast->_next = nullptr;
				break;
			}
			newLast = newLast->_next;
			counter--;
		}
	}
	_size--;
}

void List::insert(int index, int data)
{
	Block* newBlock = new Block;
	newBlock->_data = data;
	int counter = 0;
	Block* current = _first;
	while (index-counter)
	{
		counter++;
		current = current->_next;
	}
	newBlock->_next = current;
	if (index)
	{
		counter = 0;
		Block* previous = _first;
		while (index - counter > 1)
		{
			counter++;
			previous = previous->_next;
		}
		previous->_next = newBlock;
	}
	else
	{
		_first = newBlock;
	}
	_size++;
}

void List::removeAt(int index)
{
	int counter = 0;
	Block* victim = _first;
	while (!(counter == index))
	{
		victim = victim->_next;
		counter++;
	}
	if (!index)
	{
		_first = victim->_next;
		delete victim;
	}
	else
	{
		Block* previous = _first;
		Block* next = victim->_next;
		while (counter > 1)
		{
			previous = previous->_next;
			counter--;
		}
		delete victim;
		previous->_next = next;
	}
	_size--;
}

