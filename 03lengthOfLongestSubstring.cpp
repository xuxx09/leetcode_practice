#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring_01(string s)
{
    vector<char> str;
    size_t length = 0;
    vector<char> :: iterator iter;
    for(size_t i = 0; i < s.size(); i++)
    {
        //test if has the repeat char
        iter = find(str.begin(), str.end(), s[i]);
        if(iter != str.end() && !str.empty())
        {
            //this function will erase [begin, end);
            str.erase(str.begin(), iter);
            str.erase(str.begin());
        }

        str.push_back(s[i]);
        length = length > str.size() ? length : str.size();
    }
    return length;
}

//this function use the idea of the map
int lengthOfLongestSubstring_02(string s)
{
    int Index[256];
    for(int i = 0; i < 256; i++)
    {
        Index[i] = -1;
    }
    int curlen = 0;
    int maxlen = 0;
    int start = 0;

    for(size_t i = 0; i < s.size(); i++)
    {
        // The first time s[i] appear,It will be
        //less than start, the second time appear,
        // it will bigger than start.
        if(Index[s[i]] < start)
        {
            Index[s[i]] = i;
            curlen++;
        }
        else
        {
            start = Index[s[i]] + 1;
            Index[s[i]] = i;
            curlen = i - start + 1;
        }
        maxlen = maxlen > curlen ? maxlen : curlen;
    }
    return maxlen;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
