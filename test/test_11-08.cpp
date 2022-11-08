//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;//给a取一个别名叫b
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	a = 20;
//	b = 30;
//
//	return 0;
//}

//int main()
//{
//	// 1、引用在定义时必须初始化
//	//int a = 10;
//	//int& b;
//
//	// 2、一个变量可以有多个引用
//	//int a = 10;
//	//int& b = a;
//	//int& c = a;
//	//int& d = b;
//	//double d = 1.1;//命名冲突，同一个作用域里不能同名
//
//	// 3、引用一旦引用一个实体，再不能引用其他实体
//	int a = 10;
//	int& b = a;
//	int c = 20;
//	b = c;//把c赋值给b
//}
// 1、引用做参数
// _Z4swappipi
//void swap(int* p1, int* p2) // 传地址
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//// _Z4swapriri
//void swap(int& r1, int& r2) // 传引用
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}

// _Z4swapii
//void swap(int r1, int r2)   // 传值
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}

// 他们三个构成函数重载
// 但是swap(x, y);调用时存在歧义，他不知道调用，传值还是传引用
// 类似以前讲的这个,他们构成重载，但是存在歧义
// void f();
// void f(int x = 0, int y = 0);

//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//	swap(x, y);
//
//	return 0;
//}

//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}


 //传引用返回
//int& Add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(10, 20);
//	cout <<"Add(1, 2) is :" << ret << endl;
//
//	return 0;
//}
// 假设x是一个大对象或者是深拷贝的对象
// 那么尽量用引用传参，减少拷贝。如果f函数中不改变x,建议尽量用cosnt引用传参
//void f(int& x)
//void f(const int& x)
//{
//	cout << x << endl;
//}
//// 常引用
//int main()
//{
//	// 权限放大  不可以
//	//const int a = 10;
//	//int& b = a;
//
//	// 权限不变 可以
//	const int a = 10;
//	const int& b = a;
//
//	// 权限的缩小 可以
//	int c = 10;
//	const int& d = c;
//
//	f(a);
//	f(c);
//	f(10);
//
//	return 0;
//}
#include <iostream>
using namespace std;

inline int Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int ret = Add(1, 2);
	cout << ret << endl;
	return 0;
}

//int Max(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//int main()
//{
//
//	cout << "Max (20,10): " << Max(20, 10) << endl;
//	cout << "Max (0,200): " << Max(0, 200) << endl;
//	cout << "Max (100,1010): " << Max(100, 1010) << endl;
//	return 0;
//}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int x = 0, y = 1;
	Swap(x, y);
	return 0;
}
int main()
{
	const int a = 0;
	int b = 0;
	// 自动推导c的类型
	auto c = a;
	auto d = 'A';
	auto e = 10.11;

	// typeid打印变量的类型
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;
}