#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	/*string s;
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
}