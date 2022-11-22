#include "Date.h"

	Date::Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;

		if (!(_year >= 0
			&& (month > 0 && month < 13)
			&& (day > 0 && day <= GetMonthDay(year, month))))
		{
			cout << "非法日期->";
			// this->Print();
			Print();
		}
	}
	void Date::Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	int Date::GetMonthDay(int year, int month)
	{
		static int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = monthday[month];
		if (month == 2 && ((year % 4 == 0 && year % 400 != 0) || (year % 400 == 0)))
		{
			day++;
		}
		return day;
	}
	// 日期+=天数
	Date& Date::operator+=(int day)
	{
		if (day < 0)
		{
			return (*this) -= -day;
		}
		_day += day;
		if (_day > GetMonthDay(_year,_month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;

			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	// 日期+天数
	Date Date::operator+(int day)
	{
		Date ret(*this);

		ret += day;
		return ret;
	}
	
	
	// 日期-=天数
	Date& Date::operator-=(int day)
	{
		if (day < 0)
		{
			return (*this) += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	// 日期-天数
	Date Date::operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}
	// 日期-日期 返回天数
	int Date::operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;

		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		//计算两个日期相差天
		int count = 0;
		while (max != min)
		{
			++min;
			++count;
		}
		return count * flag;
	}

	
	// 前置++
	Date& Date::operator++()
	{
		*this += 1;
		return *this;
	}
	// d1++; 后置为了跟前置++，进行区分
	// 增加一下参数占位，跟前置++构成函数重载
	// 后置++
	Date Date::operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	// 前置--
	Date& Date::operator--()
	{
		*this -= 1;
		return *this;

	}
	// 后置--
	Date Date::operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	
	
	Date& Date:: operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}
// 重载 > 运算符，用于把两个 Date 对象比较大小
	bool Date::operator>(const Date& d)//	bool operator>(Date* const this,Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// ==运算符重载
	bool Date::operator==(const Date & d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return true;
		else
			return false;
	}

	// <运算符重载
	bool Date::operator < (const Date& d)
	{
		return !(*this >= d);
	}
	// >=运算符重载
	bool Date::operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	
	}

	// <=运算符重载
	bool Date::operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=运算符重载
	bool Date::operator!=(const Date& d)
	{
		return  !(*this == d);
	}