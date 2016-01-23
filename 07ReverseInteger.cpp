#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
using namespace std;
//This function is the normal way to solve the problem.
// but the function will cost to much time.
int reverse_abandon(int x)
{
    if(x == INT_MIN) return 0;
    int y = abs(x);
    char s[100];
    int len = sprintf(s, "%d", y);
    s[len] = '\0';
    string str = s;
    string reverseString;
    for (int i = str.size()-1; i >= 0; i--)
    {
        reverseString.push_back(str[i]);
    }
    long result = atol(reverseString.data());
    result = x < 0 ? -result : result;
    if( INT_MAX <= result || result <= INT_MIN) return 0;
    else return result;
}

int reverse(int x)
{
    int sign = x < 0 ? -1 : 1;
    x = abs(x);//When x = INT_MAX it will return INT_MAX;
    long long out = 0;
    while( x > 0)
    {
        out = out * 10 + x % 10;
        x = x / 10;
    }
    out = sign * out;
    if ( out < INT_MIN || out > INT_MAX)
        return 0;
    else return out;
}

int main()
{
    cout << abs(INT_MIN) << endl;
    return 0;
}
