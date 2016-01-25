#include <iostream>

using namespace std;

bool isMatch(string s, string p)
{
    /**
     * There are three kind of string in this function.
     * 1. p[1] == '*';
     * 2. p[0] == '.';
     * 3. p[0] == 'char'
     */

     if( p.empty()) return s.empty();
     if(p[1] == '*') return isMatch(s, p.substr(2)) || \
        ( !s.empty() && (p[0] == '.'  || s[0] == p[0]) && isMatch(s.substr(1), p) );
     if(p[0] == '.') return !s.empty() && isMatch(s.substr(1),p.substr(1));
     return (!s.empty() && s[0] == p[0] && isMatch(s.substr(1), p.substr(1)));
}


int main()
{
    cout << isMatch("ab", "aab") << endl;
    return 0;
}
