#include "Date.h"

int main()
{
	Date d1(2022, 11, 22);
	Date d2(2022, 11, 23);
	Date d3(2022, 11, 24);
	//d1.Print();
	// 两个已经存在的对象之间进行赋值拷贝
	//d1 = d2;//d1.operator>(d2);
	//d1.Print();

	// 拷贝构造:一个已经存在的对象拷贝初始化一个马上创建实例化的对象
	Date d4(d1);  // 拷贝构造
	Date d5 = d1; // 拷贝构造

	int d12 = d2 - d1;
	cout << d12 << endl;
	return 0;
}