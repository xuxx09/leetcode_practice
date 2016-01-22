#include <iostream>

using namespace std;

// In this method we extend the string
// from the center place.

string extendPalindrome(string str, int l, int r)
{
    while (l >= 0 && r < str.size() && str[l] == str[r])
    {
        l--;
        r++;
    }
    return str.substr(l+1, r-l-1);
}

string longestPalindrome(string str)
{
    string maxstr;
    if (str.size() < 2)
    {
        return str;
    }
    for(size_t i = 0; i < str.size() -1; i++)
    {
        string left = extendPalindrome(str, i, i);
        string right = extendPalindrome(str, i, i+1);
        left = left.size()> right.size() ? left : right;
        maxstr = left.size()>maxstr.size() ? left : maxstr;
    }
    return maxstr;
}

int main()
{
    string str = "a";
    cout<<IsPalindrome(str);
    //cout<<longestPalindrome(str);

}
