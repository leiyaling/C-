#include <iostream>
using namespace std;

//class A {};
//class B : public A {};
//class Person {
//public:
//	~Person() { cout << "~Person()" << endl; }
//	/*virtual A* BuyTicket() 
//	{
//		cout << "ÂòÆ±-È«¼Û" << endl;
//		return new A;
//	}*/
//};
//class Student : public Person {
//public:
//	~Student() { cout << "~Student()" << endl; }
//	/*virtual B* BuyTicket() 
//	{
//		cout << "ÂòÆ±-°ë¼Û" << endl;
//		return new B;
//	}*/
//};
////void Func(Person& p)//void Func(Person* p)
////{
////	p.BuyTicket();
////}
//int main()
//{
//	Person ps;
//	Student st;
//	/*Func(ps);
//	Func(st);*/
//	return 0;
//}
//class Person {
//public:
//	~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	~Student() { cout << "~Student()" << endl; }
//};
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//
//	return 0;
//}
class A { public: void test(float a) { cout << a; } }; 
class B :public A { public: void test(int b) { cout << b; } }; 
void main() { A* a = new A; B* b = new B; a = b; a->test(1.1); }
