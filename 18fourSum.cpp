#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector< vector<int> >fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > total;
        int n = nums.size();
        if(n<4) return total;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;//这里产生的是最小值
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;//这里产生的是最大值
            for(int j = i+1; j<n-2; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;//这里是让j的值加1
                int left = j+1, right = n-1;
                while(left<right)
                {
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target) left++;
                    else if (sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});//只能在c++11中使用
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }

                }
            }
        }
        return total;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
