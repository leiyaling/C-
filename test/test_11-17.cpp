#include <iostream>

using namespace std;

//class Line
//{
//public:
//    // ���ǹ��캯��
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
    // ��������(��������)
    int _year = 1970;
    int _month = 1;
    int _day = 1;
    // �Զ�������
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
//    // ��Line���й��캯�����κ󣬴������ͨ�����룬��Ϊ������������һ���޲ε�Ĭ�Ϲ��캯��
//        // ��Line���й��캯���ſ����������ʧ�ܣ���Ϊһ����ʽ�����κι��캯��������������������
//        // �޲ι��캯�����ſ��󱨴�error C2512: ��Line��: û�к��ʵ�Ĭ�Ϲ��캯������
//    // ��ȡĬ�����õĳ���
//
//    return 0;
//}