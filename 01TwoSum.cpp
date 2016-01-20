#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    map<int, int> h;
    for(int i=0; i<nums.size(); i++)
    {
        if(h.find(target-nums[i])!= h.end())//ʹ��map���д���Ѱ���Ѿ�����Ԫ���Ƿ��ܺ͵�ǰԪ�����
        {
            int index=h[target-nums[i]];
            res.push_back( min(i+1,index+1) );
            res.push_back( max(i+1,index+1) );
            break;
        }
        h.insert(pair<int, int>(nums[i],i));
        //h.insert(make_pair(nums[i], i));
    }
    return res;
}
