#pragma once
class List
{
private:
	class Block
	{
	public:
		int _data;
		Block* _next;
	};
	Block* _first;
	int _size;
public:
	List();
	~List();
	void push_front(int data);
	void push_back(int data);
	void print();
	int get_size();
	int & operator [](int index);
	void clear();
	void pop_front();
	void pop_back();
	void insert(int index, int data);
	void removeAt(int index);
};

