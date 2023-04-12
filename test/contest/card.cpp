#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int T=0;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n,k;
        cin>>n>>k;
        vector<int> ret(2*n,0);
        for(int x=0;x<2*n;x++)
            cin>>ret[x];
        while(k--)
        {
            vector<int> tmp(ret.begin(), ret.end());
            for(int j=0; j<n; ++j)
            {
                ret[2*j] = tmp[j]; 
                ret[2*j+1] = tmp[j+n];
            }
        }
        
      for(int i=0; i<2*n-1; ++i)
        cout<<ret[i]<<" ";
      cout<<ret[2*n-1]<<endl; 
    }
    return 0;
}