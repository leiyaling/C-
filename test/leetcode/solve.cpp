#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int M=0,N=0;
    cin>>M>>N;
    if(M==0)
        cout<<0;
    string s;
    string ret="0123456789ABCDEF";
    bool flag=false;
    if(M<0)
    {
        M=abs(M);
        flag=true;
    }
        
    while(M)
    {
        s+=ret[M%N];
        M/=N;
    }
    if(flag)
        s+='-';
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}