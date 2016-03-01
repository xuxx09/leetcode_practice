#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPermutation(vector<int>& nums)
{
    for(int i = nums.size()-1; i>0; i--)
    {
        if(nums[i] > nums[i-1])
        {
            int MIN = nums[i];
            int index = i;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] < MIN && nums[j] > nums[i-1])
                {
                    MIN = nums[j];
                    index = j;
                }
            }
            swap(nums[index], nums[i-1]);
            sort(&nums[i],&nums[i]+nums.size()-i);
            return ;
        }
    }
    sort(nums.begin(), nums.end());
    return;
}
int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(3);
    nextPermutation(vec);
    for(int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i];
    }
    return 0;
}
