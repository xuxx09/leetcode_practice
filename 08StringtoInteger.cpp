#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int myAtoi(string str)
{
    long long result = 0;
    int i = 0;
    int sign = 1;
    while( i < str.size() && str[i]==' ') i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i]== '-') sign = -1;
        i++;
    }
    while(str[i]<='9' && str[i]>='0' && i<str.size())
    {
        result = result * 10 + str[i]-'0';
        if(result > INT_MAX) break;
        i++;
    }
    result = result * sign;
    if(result > INT_MAX) return INT_MAX;
    if(result < INT_MIN) return INT_MIN;
    return result;
}
int main()
{
    cout<<myAtoi("1")<<endl;
    cout<<myAtoi("-79579247592379")<<endl;
    return 0;
}
