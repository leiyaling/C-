//#include <iostream>
//using namespace std;//c++库实现定义在一个叫std的命名空间中
//int main()
//{
//	cout << "Hello World" << endl;
//	return 0;
//}

//#include <iostream>
////using namespace std;//c++库实现定义在一个叫std的命名空间中
//int main()
//{
//	//指定命名空间
//	std::cout << "Hello World" << std::endl;
//	return 0;
//}

//#include <iostream>
////将常用的展开
//using std::cout;
//using std::endl;
//int main()
//{
//	cout << "Hello World" << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//// 第一个命名空间
//namespace first_space {
//    void func() {
//        cout << "Inside first_space" << endl;
//    }
//}
//// 第二个命名空间
//namespace second_space {
//    void func() {
//        cout << "Inside second_space" << endl;
//    }
//}
//int main()
//{
//    // 调用第一个命名空间中的函数
//    first_space::func();
//
//    // 调用第二个命名空间中的函数
//    second_space::func();
//
//    return 0;
//}
#include <iostream>
using namespace std;

// 第一个命名空间
namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}
// 第二个命名空间
namespace second_space {
    void func() {
        cout << "Inside second_space" << endl;
    }
}
using namespace first_space;
int main()
{
    // 调用第一个命名空间中的函数
    func();
    return 0;
}