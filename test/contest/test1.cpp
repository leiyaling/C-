#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//刷题统计
//int main()
//{
//	int a, b, n = 0;
//	cin >> a >> b >> n;
//	int ret = 0;
//	while (n > 0)
//	{
//		for (int i = 0; i < 5; i++)
//		{
//			n -= a;
//			ret++;
//			if (n <= 0)
//				break;
//		}
//		if (n <= 0)
//			break;
//		for (int i = 0; i < 2; i++)
//		{
//			n -= b;
//			ret++;
//			if (n <= 0)
//				break;
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}

//时间显示 
//int main()
//{
//	long long n = 0;
//	cin >> n;
//	long long h, m, s;
//
//	h = n / 3600000;
//	if (h > 23)
//		h %= 24;
//	n %= 3600000;
//	m = n / 60000;
//	n %= 60000;
//	s = n / 1000;
//
//	printf("%02ld:%02ld:%02ld", h, m, s);
//	return 0;
//}

//成绩分析
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int max = 0, min = 0;
//	double sum= 0;
//	int tmp = 0;
//	
//	for (int i = 0; i < n; i++)
//	{
//		cin >> tmp;
//		if (i == 0)
//		{
//			max = tmp;
//			min = tmp;
//		}
//		else
//		{
//			if (tmp > max)
//				max = tmp;
//			else if (tmp < min)
//				min = tmp;
//		}
//		sum += tmp;
//	}
//	printf("%d\n%d\n%.2lf", max, min, sum / n);
//	return 0;
//}

int main()
{
	int n = 0;
	cin >> n;
	int tmp = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	return 0;
}