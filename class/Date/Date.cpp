#include "Date.h"
int Date::GetMonthDay(int year, int month)
{
	static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = monthDayArray[month];
	if ((month==2)&&(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		day+=1;
	}
	return day;
}
 Date::Date(int year, int month , int day)
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
		//Print();
	}

}
 bool Date::operator>(const Date& d)
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
 bool Date::operator<(const Date& d)
 {
	 if (_year < d._year)
	 {
		 return true;
	 }
	 else if (_year == d._year && _month < d._month)
	 {
		 return true;
	 }
	 else if (_year == d._year && _month == d._month && _day < d._day)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }
 //bool Date::operator>=(const Date& d)
 //{

 //}
 //bool Date::operator<=(const Date& d)
 //{

 //}
 bool Date::operator==(const Date& d)
 {
	 if (_year == d._year && _month == d._month && _day == d._day)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }
 /*bool Date::operator!=(const Date& d)
 {

 }*/
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//d1 += 100
Date& Date::operator+=(int day)
{
	_day += day;
	while(_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
// d1 + 100
Date Date::operator+(int day)
{
	Date ret(*this);
	//ret.operator+=(day);
	ret += day;

	return ret;
}

// ++d1;
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

// d1++; 后置为了跟前置++，进行区分
// 增加一下参数占位，跟前置++,构成函数重载
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;

	return ret;
}