#include <iostream>

using namespace std;
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end();)
        {
            if(*iter == val)
                iter = nums.erase(iter);
            continue;
            else
                iter++;
        }
        return nums.size();
    }
    int removeElement2(vector<int>& nums, int val)
    {
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
                nums[i-count] = nums[i];
            else
            {
                count++;
            }
        }
        return nums.sizs() - count;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
