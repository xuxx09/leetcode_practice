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
    //这是一个十分简短的代码，没有进行存储空间的删除，
    //这样函数处理的速度就会更加快速
    int removeDuplicates(vector<int>& nums)
    {
        int counts=0;
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] ==  nums[i-1]) counts++;
            else nums[i-counts] = nums[i];
        }
        return n-counts;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
