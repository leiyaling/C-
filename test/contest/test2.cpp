
#include <iostream>
#include <vector>
using namespace std;

/*int main()
{
	int n=0,m=0;
	cin>>n>>m;
	int arr[n][m]={0};
	int t=0;
	cin>>t;
	int r1=0, c1=0, r2=0, c2=0;
	while(cin>>r1>>c1>>r2>>c2)
	{
		
		
		for(int i=r1;i<=r2;i++)
		{
			for(int j=c1;i<=c2;j++)
			{
				arr[i][j]=1;
			} 
		}
		t--;
		if(t==0)
			break;
	}
	int count=0;
	for(int i=0;i<n;i++)
		{
			for(int j=0;i<m;j++)
			{
				if(arr[i][j]!=1)
					count++;
			} 
		}
		cout<<count;
	return 0;
}
int main()
{
	int w=0,n=0;
	cin>>w>>n;
	int result=0;
	result=(w+n)%7;
	cout<<result;
	return 0;
}*/
int GetMonthDay(int year,int month)
{
	int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(month==2 && ((year%400==0)||(year%4==0&&year%100!=0)))
		arr[2]=29;
	return arr[month];	
		
}
int isTrue(int year,int month,int day)
{
	int x=0;
	int y=0;
	while(year)
	{
		x+=year%10;
		year/=10;
	}
	while(month)
	{
		y+=month%10;
		month/=10;
	}
	while(day)
	{
		y+=day%10;
		day/=10;
	}
	return (x==y)?1:0;
}

int main()
{
	int count=0;
	for(int i=1900;i<=9999;i++)
	{
		int year=i;
		for(int j=1;j<=12;j++)
		{
			int month=j;
			for(int k=1;k<=GetMonthDay(year,month);k++)
			{
				if(isTrue(year,month,k)==1)
					count++;
			}
		}
	}
	cout<<count;
}
	/*
	int arr[30]={99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77 };
	int count=0;
	int n=0;
	for(int i=0;i<30;i++)
	{
		for(int j=i+1;j<30;j++)
		{
			n++;
			if(arr[i]*arr[j]>=2022)
			{
				count++;
			}
		}
	}
	cout<<n<<count;
	return 0;
}

int main()
{
	string s;
	cin >> s;
	string tmp;
	set<char> st;
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		tmp.clear();
		st.clear();
		for (int j = i; j < s.size(); j++)
		{
			tmp += s[j];
			for (int n=0;n<tmp.size();n++)
			{
				st.insert(tmp[n]);
			}
			sum += st.size();
		}
	}
	cout << sum;*/
/* 
int main()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i <=n; i++) 
	{
        int x = i;
        while (x) {
            int t = x % 10;
            if (t == 0 || t == 1 || t == 2 || t == 9) {
                res += i;
                break;
            }
            x /= 10;
        }
    }
    cout << res;
    return 0;
}*/




















