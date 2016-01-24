#include <iostream>

using namespace std;
bool isPalindrome(int x)
{
    if(x<0) return 0;
    int result = 0;
    int y = x;
    while(x)
    {
        result = result * 10 + x % 10;
        x = x / 10;
    }
    return result == y;
}

int main()
{
    cout << isPalindrome(1234321)  << endl;
    return 0;
}
