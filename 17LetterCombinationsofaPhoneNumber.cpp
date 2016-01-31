#include <iostream>
#include <vector>
using namespace std;
// This is a very easy way to understand solution.
vector<string> letterCombinations_01(string digits)
{
    string mp[256];
    mp['2']= "abc";
    mp['3']= "def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";

    vector<string> vec;
    int sum = 0;
    for(int i=0; i<digits.size(); i++)
    {
        sum = sum * 10 + mp[digits[i]].size();
    }
    for(int i = 0; i < sum; i++)
    {
        int n = i;
        string str;
        for(int j = digits.size()-1; j >=0; j--)
        {
            if( (n%10) >= mp[digits[j]].size()) { str.clear();break;}
            char ch = mp[digits[j]][n%10];
            str.insert(str.begin(),ch);
            n = n/10;
        }
        if( str.size())
        vec.push_back(str);
    }
    return vec;
}


vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(!digits.size()) return res;
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}

int main()
{

    vector<string> vec= letterCombinations("23");
    cout<<vec.size();
    return 0;
}
