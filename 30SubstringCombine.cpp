#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> findSubstring(string s, vector<string>& words)
{
    int n = s.size();
    int wl = words[0].size();
    int ws = words.size();
    vector<int> vec;
    map<string, int> mp1, mp2;
    for(int i = 0; i < ws; i++)
    {
        mp1[words[i]]++;

    }

    for(int start = 0; start <= n-wl*ws; start++)
    {

        /**»Ö¸´mapµÄÖµ*/
        mp2 = mp1;
        string str = s.substr(start, wl*ws);
        int cur;
        for(cur = 0; cur < wl*ws; cur = cur + wl)
        {
            if(  mp2[str.substr(cur, wl)] > 0)
            {
                mp2[str.substr(cur,wl)]--;
                continue;
            }
            else
            {
                break;
            }
        }
        if(cur == wl*ws)
            vec.push_back(start);
    }
    return vec;
}
int main()
{
    string s = "barfoothefoobarman";
    vector<string> vec;
    vec.push_back("foo");
    vec.push_back("bar");
    findSubstring(s, vec);
    return 0;
}
