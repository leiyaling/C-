#include <iostream>
using namespace std;
class Person {
public:
	virtual void func1()
	{
		cout << "Person::func1()" << endl;
	}
	void func2()
	{
		cout << "Person::func2()" << endl;
	}
};
class Student : public Person {
public:
	virtual void func1()
	{
		cout << "Student::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "Student::func2()" << endl;
	}
	void func3()
	{
		cout << "Student::func3()" << endl;
	}
};
//class Soldier : public Person {
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ÂòÆ±-Ãâ·Ñ" << endl;
//	}
//};
int main()
{
	Person p;
	Student s;
	/*Person* p1 = new Student();
	Person* p2 = new Soldier();
	p1->BuyTicket();
	p2->BuyTicket();*/
	return 0;
}