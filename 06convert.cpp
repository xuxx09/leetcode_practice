#include <iostream>

using namespace std;

string convert(string s, int numRows)
{
    if(numRows < 2) return s;
    string str;
    for(int i = 1; i<=numRows; i++)
    {
        if(i==1 || i==numRows)
        {
            int tag = i-1;
            while( tag < s.size() )
            {
                str.push_back(s[tag]);
                tag = tag + (numRows - 1) * 2;
            }

        }
        else
        {
            int tag = i-1;
            bool flag= true;
            while(tag < s.size() )
            {
                str.push_back(s[tag]);
                if(flag)
                {

                    tag += (numRows - i) * 2;
                    flag = !flag;
                }
                else
                {
                    tag += (i-1) * 2;
                    flag = !flag;
                }

            }
        }
    }
    return str;
}


int main()
{
    cout << convert("A", 1) << endl;
    return 0;
}
