class Solution {
    string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void _letterCombinations(const string& digits,size_t i,string combinStr,vector<string>& strV){
        if(i == digits.size())
        {
            strV.push_back(combinStr);
            return;
        }
        string str = arr[digits[i] - '0'];//字符转化为数字
        for(int j=0;j<str.size();j++)
        {
            _letterCombinations(digits,i+1,combinStr + str[j],strV);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combinStr;//组合字符串
        vector<string> strV;
        if(digits.empty())
            return strV;
        _letterCombinations(digits,0,combinStr,strV);
        return strV;
    }
};