#include "Date.h"

int main()
{
	Date d1(2022, 11, 22);
	Date d2(2022, 11, 23);
	Date d3(2022, 11, 24);
	//d1.Print();
	// �����Ѿ����ڵĶ���֮����и�ֵ����
	//d1 = d2;//d1.operator>(d2);
	//d1.Print();

	// ��������:һ���Ѿ����ڵĶ��󿽱���ʼ��һ�����ϴ���ʵ�����Ķ���
	Date d4(d1);  // ��������
	Date d5 = d1; // ��������

	int d12 = d2 - d1;
	cout << d12 << endl;
	return 0;
}