#include <iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date()
//	{
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	return 0;
//}

class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity=4)
	{
		_a = (DataType*)malloc(sizeof(DataType) * capacity);
		_capacity = capacity;
		_size = 0;
	}
	void pushStack(DataType data)
	{
		_a[_size++] = data;
	}
	~Stack()
	{
		if (_a)
		{
			free(_a);
			_a =nullptr;
			_capacity = 0;
			_size = 0;
		}
		
	}
private:
	DataType* _a;
	size_t _capacity;
	size_t _size;
};
int main()
{
	Date d;
	return 0;
}