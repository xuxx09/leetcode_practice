#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
    if( strs.empty() ) return "";
    string MaxLength = strs[0];
    for(int i = 0; i < strs.size(); i++)
    {
        int j = 0;
        int length = min(strs[i].size(),MaxLength.size());
        while(strs[i][j] == MaxLength[j] && j <= length)
        {
            j++;

        }
        MaxLength = MaxLength.substr(0,j);
    }
    return MaxLength;
}

int main()
{
    vector<string> strs;
    strs.push_back("a");
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
