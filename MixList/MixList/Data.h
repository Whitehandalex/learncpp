#pragma once
class Data
{
private:
	void* _data;
	int _code;
public:

	Data(int code, void* data) : _data(data), _code(code) {}
	~Data();
	int getCode() { return _code; }
	void const *getData() { return _data; }
};

