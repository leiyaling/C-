#include "Date.h"
void TestDate1()
{
	Date d1(2022, 2, 2);
	Date d2(2022, 22, 2);
	Date d3(2022, 12, 32);
	d1.Print();
	d2.Print();
	d3.Print();
	////һ���Ѿ����ڵĶ��󿽱���ʼ��һ�����ϴ���ʵ�����Ķ���
	//Date d4(d1);//��������
	//Date d5 = d1;//��������

	////�����Ѿ����ڵĶ���֮�俽������
	//d2 = d1 = d3;//d1.operator
	////d1 = d3;//d1.operator(d3)
}
void TestDate2()
{
	Date d1(2022, 1, 16);
	Date ret = d1 + 100;
	ret.Print();

	d1 += 100;
	d1.Print();

	Date ret1 = d1++;  // d1.operator++(&d1, 0);
	Date ret2 = ++d1;  // d1.operator++(&d1);
}


int main()
{
	//TestDate1();
	TestDate2();
	return 0;
}