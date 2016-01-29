#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    vector<int> vec;
    int i = 0, last = nums.size()-1;
    while(i < last)
    {
        //start from the first and last index.
        int a = nums[i], j = i+1, k = last;
        while(j<k)
        {
            int b = nums[j], c = nums[k], sum = a+b+c;
            //add the result.
            if(sum == 0)
            {
                vec.push_back(a);
                vec.push_back(b);
                vec.push_back(c);
                result.push_back(vec);
                vec.clear();
            }
            //delete the duplicate triplets.
            if(sum <= 0)while(b == nums[j] && j < k)j++;
            if(sum >= 0)while(c == nums[k] && j < k)k--;
        }
        while(a == nums[i] && i < last)i++;
    }
    return result;
}

