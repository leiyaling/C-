//#include <iostream>
//using namespace std;//c++��ʵ�ֶ�����һ����std�������ռ���
//int main()
//{
//	cout << "Hello World" << endl;
//	return 0;
//}

//#include <iostream>
////using namespace std;//c++��ʵ�ֶ�����һ����std�������ռ���
//int main()
//{
//	//ָ�������ռ�
//	std::cout << "Hello World" << std::endl;
//	return 0;
//}

//#include <iostream>
////�����õ�չ��
//using std::cout;
//using std::endl;
//int main()
//{
//	cout << "Hello World" << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//// ��һ�������ռ�
//namespace first_space {
//    void func() {
//        cout << "Inside first_space" << endl;
//    }
//}
//// �ڶ��������ռ�
//namespace second_space {
//    void func() {
//        cout << "Inside second_space" << endl;
//    }
//}
//int main()
//{
//    // ���õ�һ�������ռ��еĺ���
//    first_space::func();
//
//    // ���õڶ��������ռ��еĺ���
//    second_space::func();
//
//    return 0;
//}
#include <iostream>
using namespace std;

// ��һ�������ռ�
namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}
// �ڶ��������ռ�
namespace second_space {
    void func() {
        cout << "Inside second_space" << endl;
    }
}
using namespace first_space;
int main()
{
    // ���õ�һ�������ռ��еĺ���
    func();
    return 0;
}