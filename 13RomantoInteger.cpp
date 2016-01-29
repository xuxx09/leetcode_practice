#include <iostream>
#include <map>
#include <string>
using namespace std;
    int romanToInt(string s)
{
//    map<char, int> T = { { 'I' , 1 },
//        { 'V' , 5 },
//        { 'X' , 10 },
//        { 'L' , 50 },
//        { 'C' , 100 },
//        { 'D' , 500 },
//        { 'M' , 1000 }
//    };
    int mp[256]={0,};
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    int sum = mp[s[s.size()-1]];
    for (int i = s.length() - 2; i >= 0; --i)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            sum -= mp[s[i]];
        }
        else
        {
            sum += mp[s[i]];
        }
    }

    return sum;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
