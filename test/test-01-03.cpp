#include <iostream>
using namespace std;
//两位数的时候只需要对平方取模100进行比较，三位数平方取模1000， 四位数取模10000
int main() {
    int n;
    cin>>n;
    int count = 0;
    int m = 10;
    for(int i = 0;i <= n;i++)
    {
        int ret = i * i;
        if(i == m)//两位数的时候成为100，三位数的时候成为1000
            m *= 10;
        if(ret % m == i)
            count++;
    }
    cout<<count;
    return 0;
}