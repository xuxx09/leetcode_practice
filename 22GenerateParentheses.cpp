#include <iostream>
/**
 *对于这个问题，首先分析是不是动态规划问题，因为没有产生子问题重叠，
 *所以不是动态规划问题。
 */
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }


    void addingpar(vector<string>& v, string str, int left, int right)
    {
        if(left==0 && right==0)
        {
            v.push_back(str);
            return;
        }
        if(right > 0){addingpar(v, str+')', left, right-1); }
        if(left > 0){addingpar(v, str+'(', left-1, right+1); }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
