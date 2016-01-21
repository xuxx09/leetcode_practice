#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays_01(vector<int>& nums1, vector<int>& nums2)
{
    size_t length1 = nums1.size();
    size_t length2 = nums2.size();
    size_t index1 = 0;
    size_t index2 = 0;
    vector<int> vec;
    while(index1 < length1 && index2 < length2)
    {
        if(nums1[index1] > nums2[index2])
        {
            vec.push_back(nums2[index2]);
            index2++;
        }
        else
        {
            vec.push_back(nums1[index1]);
            index1++;
        }
    }
    while(index1 < length1)
    {
        vec.push_back(nums1[index1]);
        index1++;
    }
    while(index2 < length2)
    {
        vec.push_back(nums2[index2]);
        index2++;
    }
    if(vec.size()%2)
        return vec[vec.size()/2];
    else
        return ( vec[vec.size()/2] + vec[vec.size()/2-1] )/ 2.0;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
