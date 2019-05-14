#include "pch.h"
#include <iostream>

using namespace std;

class Dictionary
{
private:
	int* _arr;
	int _capacity;
public:
	Dictionary()
	{
		_arr = nullptr;
		_capacity = 0;
	}
	~Dictionary()
	{
		delete[]_arr;
	}
	int & operator[](const char* key)
	{
		int index = 0;
		for (int i = 0;i < strlen(key);i++)
		{
			index += key[i];
		}
		if (index > _capacity)
		{
			int* temp = new int[index+1] {};
			for (int i = 0;i < _capacity;i++)
			{
				temp[i] = _arr[i];
			}
			delete[]_arr;
			_arr = temp;
			_capacity = index + 1;
		}
		return _arr[index];
	}
};
int main()
{
	Dictionary dict;
	dict["test1"] = 1;
	dict["key2"] = 33;
	dict["qwerty"] = 5;
	cout << dict["test1"] << " " << dict["key2"] << " " << dict["qwerty"] << endl;
}

