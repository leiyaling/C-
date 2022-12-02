#include <iostream>

using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//			
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);//调用构造函数和析构函数
//	free(p1);
//	delete p2;
//	return 0;
//}
//class C {
//
//};
//int main()
//{
//	C* c = new C();
//	delete c;
//	return 0;
//}
 
// new_ delete.CPP

//extern "C" void* malloc (unsigned int) ;
//extern "C" void free (void*) ;
//
//void* operator new (unsigned int size)
//{
//	return malloc(size);
//}
//
//void operator delete (void* p)
//{
//	free(p);
//}
//
//void* operator new[](unsigned int size)
//{
//	return malloc(size);
//}
//void operator delete[](void* p)
//{
//	free(p);
//}
