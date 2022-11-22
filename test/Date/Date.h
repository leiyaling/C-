#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1, int month = 1, int day = 1);
	void Print();
	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
		Date& operator=(const Date & d);
		// ����+=����
		Date& operator+=(int day);
		// ����+����
		Date operator+(int day);
		// ����-����
		Date operator-(int day);
		// ����-=����
		Date& operator-=(int day);
		// ǰ��++
		Date& operator++();
		// ����++
		Date operator++(int);
		// ����--
		Date operator--(int);
		// ǰ��--
		Date& operator--();

		// >���������
		bool operator>(const Date & d);
		// ==���������
		bool operator==(const Date & d);
		// >=���������
		bool operator >= (const Date & d);

		// <���������
		bool operator < (const Date & d);
		// <=���������
		bool operator <= (const Date & d);
		// !=���������
		bool operator != (const Date & d);
		// ����-���� ��������
		int operator-(const Date & d);
private:
	int _year;
	int _month;
	int _day;
};
