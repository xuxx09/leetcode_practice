#include <iostream>

using namespace std;
//判断是不是回文串
bool IsPalindrome(string str, int left, int right)
{
    while(left <= right)
    {
        if(str[left] == str[right])
        {
            left++;
            right--;
        }
        else
            return false;
    }
    return true;
}
int maxlen;
string s;
string longestPalindrome(string str, int left, int right)
{

    if( IsPalindrome(str, left, right) )
    {
        maxlen = right - left + 1;
        s = str.substr(left, right-left+1);
    }
    else
    {

        string leftlen = longestPalindrome(str, left+1, right);
        string rightlen = longestPalindrome(str, left, right-1);
        s = leftlen.size() > rightlen.size() ? leftlen : rightlen;
    }
    return s;
}

int longestPalindrome_02(string str, int left, int right)
{

    if( IsPalindrome(str, left, right) )
    {
        maxlen = right - left + 1;
    }
    else
    {

        int leftlen = longestPalindrome_02(str, left+1, right);
        int rightlen = longestPalindrome_02(str, left, right-1);
        maxlen = max(leftlen, rightlen);
    }
    return maxlen;
}

int main()
{
    string s = "niniin";
    cout << IsPalindrome(s, 0, s.size()-1) << endl;
    cout << longestPalindrome_02(s, 0, s.size()-1);
    return 0;
}
