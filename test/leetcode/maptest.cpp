#include <iostream>
using namespace std;
#include <map>
#include <set>
 
typedef pair<string,int> Word;
class Compare
{
public:
    bool operator()(const Word& left, const Word& right)
    {
        // 次数从大到小排序
        // 如果次数相同，再按照单词字典序排序
        return left.second > right.second || left.first < right.first;
    }
};
 
int main()
{
    string s;
    while(getline(cin, s))
    {
        map<string, int> m;
        string temp;
        
        // 分割单词，采用map统计每个单词出现的次数
        for(size_t i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ' || s[i] == ',' || s[i] == '.')
            {
                // 一个单词解析结束
                if(temp != "")
                    m[temp]++;
                
                temp = "";
            }
            else
            {
                // 不区分大小写，那么A和a算是一个单词，故需要将大小写统一
                temp += tolower(s[i]);
            }
        }
        
        set<Word, Compare> s;
        // 将map中的<单词，次数>放到set中，并按照次数升序，次数相同按照字典序规则排序
        for(auto& e : m)
        {
            s.insert(e);
        }
        
        // 将本次统计到的结果按照要求输出
        for(auto& e : s)
            cout<<e.first<<":"<<e.second<<endl;
        cout<<endl;
    }
    return 0;
}