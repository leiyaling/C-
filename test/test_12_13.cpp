#include<iostream>
using namespace std;

class A
{
public:
    A(int a)
        :_a1(a)
        , _a2(_a1)
    {}

    void Print() {
        cout << _a1 << " " << _a2 << endl;
    }
private:
    int _a2;
    int _a1;
};
class B
{
public:
    B(int b)
        :_b(b)
    {
        cout << "B()" << " " << endl;
    }
    ~B()
    {
        cout << "~B()" << " " << endl;
    }
private:
    int _b;

};
class C :public B
{
public:
    C(int b,int c)
        :B(b)
        ,_c(c)
    {
        cout << "C()" << " " << endl;
    }
    ~C()
    {
        cout << "~C()" << endl;
    }
private:
    int _c;


};
int main() {
    /*A aa(1);
    aa.Print();*/
    //B bb(1);
    C cc(1,2);
    return 0;
}
