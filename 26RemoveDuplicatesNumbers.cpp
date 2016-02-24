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
    //����һ��ʮ�ּ�̵Ĵ��룬û�н��д洢�ռ��ɾ����
    //��������������ٶȾͻ���ӿ���
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
