#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string FindMax(const string& line)
{
    // 如果存在王炸直接返回王炸
    if (line.find("joker JOKER") != string::npos)
        return "joker JOKER";
    // 分割两手牌
    string poker1 = line.substr(0, line.find('-'));
    string poker2 = line.substr(line.find('-') + 1);
    // 计算两手牌的牌数
    int poker1_cnt = count(poker1.begin(), poker1.end(), ' ') + 1;
    int poker2_cnt = count(poker2.begin(), poker2.end(), ' ') + 1;
    // 获取两手牌各自的第一张牌
    string poker1_first = poker1.substr(0, poker1.find(' '));
    string poker2_first = poker2.substr(0, poker2.find(' '));
    // 按照斗地主规则比较牌的大小
    if (poker1_cnt == poker2_cnt)
    {
        // 只需要比较谁的下标比较大即可
        string str = "345678910JQKA2jokerJOKER";
        if (str.find(poker1_first) > str.find(poker2_first))
            return poker1;
        else
            return poker2;
    }
    // 不满足牌数一样的，判断是否存在炸，是炸的大
    if (poker1_cnt == 4)
        return poker1;
    else if (poker2_cnt == 4)
        return poker2;
    // 不满足牌数一样，还不存在炸的，不能比较
    return "ERROR";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << FindMax(line) << endl;
    }
    return 0;
}