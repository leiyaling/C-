#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int w=0,h=0,res=0;
    cin>>w>>h;
    vector<vector<int> > ret(w, vector<int>(h, 1));
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(ret[i][j]==1)
            {
                res++;
                // 标记不能放蛋糕的位置
                if((i+2)<w)
                    ret[i+2][j] = 0;
                if((j+2)<h)
                    ret[i][j+2] = 0;
            }
        }
    }
    cout << res;

    return 0;
}