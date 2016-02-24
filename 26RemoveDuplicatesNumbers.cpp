#include <iostream>

using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() <= 1) return nums.size();

        vector<int>::iterator iter = nums.begin();
        int rep = *iter;
        iter++;
        while(iter != nums.end())
        {
            if(rep == *iter)
            {
                iter = nums.erase(iter);
                continue;
            }
            rep = *iter;
            iter++;
        }
        return nums.size();
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
