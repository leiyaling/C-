#include <iostream>
using namespace std;
#include <string>
int main() {
    string s;
    cin >> s;
    int a[26]={0};
    for(int i=0;i<s.size();i++)
    {
        a[s[i]-'a']++;
    }

    for(int j=0;j<s.size();j++)
    {
        if(a[s[j]-'a']==1)
             {
                  cout<<s[j]<<endl;
                  break;
             }
             if(j==s.size()-1)
                 cout<<"-1"<<endl;
    }
    return 0;
}