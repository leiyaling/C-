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
			cout << "�Ƿ�����->";
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
	// ����+=����
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
	// ����+����
	Date Date::operator+(int day)
	{
		Date ret(*this);

		ret += day;
		return ret;
	}
	
	
	// ����-=����
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
	// ����-����
	Date Date::operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}
	// ����-���� ��������
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
		//�����������������
		int count = 0;
		while (max != min)
		{
			++min;
			++count;
		}
		return count * flag;
	}

	
	// ǰ��++
	Date& Date::operator++()
	{
		*this += 1;
		return *this;
	}
	// d1++; ����Ϊ�˸�ǰ��++����������
	// ����һ�²���ռλ����ǰ��++���ɺ�������
	// ����++
	Date Date::operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	// ǰ��--
	Date& Date::operator--()
	{
		*this -= 1;
		return *this;

	}
	// ����--
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
// ���� > ����������ڰ����� Date ����Ƚϴ�С
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
	// ==���������
	bool Date::operator==(const Date & d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return true;
		else
			return false;
	}

	// <���������
	bool Date::operator < (const Date& d)
	{
		return !(*this >= d);
	}
	// >=���������
	bool Date::operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	
	}

	// <=���������
	bool Date::operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=���������
	bool Date::operator!=(const Date& d)
	{
		return  !(*this == d);
	}