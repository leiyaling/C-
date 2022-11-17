#include <iostream>

using namespace std;

//class Line
//{
//public:
//    // 这是构造函数
//    /*Line(double len)
//    {
//        cout << "Object is being created, length = " << len << endl;
//        length = len;
//    }*/
//
//private:
//    double length;
//};

class Time
{
public:
    ~Time()
    {
        cout << "~Time()" << endl;
    }
private:
    int _hour;
    int _minute;
    int _second;
};
class Date
{
private:
    // 基本类型(内置类型)
    int _year = 1970;
    int _month = 1;
    int _day = 1;
    // 自定义类型
    Time _t;
};
int main()
{
    Date d;
    return 0;
}


//int main()
//{
//    Line line;
//    // 将Line类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
//        // 将Line类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
//        // 无参构造函数，放开后报错：error C2512: “Line”: 没有合适的默认构造函数可用
//    // 获取默认设置的长度
//
//    return 0;
//}