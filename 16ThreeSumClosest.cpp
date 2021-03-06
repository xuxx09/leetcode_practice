#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    if(nums.size() < 3) return 0;
    int closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for(int first = 0; first < nums.size()-2; ++first)
    {
        if(first > 0 && nums[first] == nums[first-1]) continue;
        int second = first + 1;
        int third = nums.size() - 1;
        while(second < third)
        {
            int curSum = nums[first] + nums[second] + nums[third];
            if(curSum == target) return curSum;
            if(abs(target-curSum) < abs(target - closest))
            {
                closest = curSum;
            }
            if(curSum > target)
            {
                --third;
            }
            else
            {
                ++second;
            }
        }
    }
    return closest;
}

int main()
{
    int arr[5] = {1,3,5,7,9};
    vector<int> vec(arr , arr+5);
    cout << threeSumClosest(vec, 7) << endl;
    return 0;
}
