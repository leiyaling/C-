#include<iostream>
#include<vector>
using namespace std;
int main()
{
	/*int n;
	cin >> n;
	int a[200];
	int i = 0;
	while (cin >> a[i])
	{
		i++;
		char c = cin.get();
		if (c == '\n')
			break;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n -1-i ; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}*/
	int n;
	cin >> n;
	int sum = 0;
	int min = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		if (i == 0)
		{
			max = min = tmp;

		}
		else
		{
			if (tmp > max)
				max = tmp;
			else if (tmp < min)
				min = tmp;
		}
		sum += tmp;
	}
	
	float avg =sum / (double)n;
	printf("%d %d %.2f",max,min,avg);
	return 0;
}