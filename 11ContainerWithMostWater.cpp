#include <iostream>

using namespace std;
//以x轴为中心，考虑问题，可以获得更加明确的信息
int maxArea_01(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
//提交后显示超时。
int maxArea(vector<int>& height)
{
    int water = 0;
    int h,l;
    for(int i = 0; i < height.size(); i++)
    {
        h = height[i];
        l = i;
        for(int j=i+1; j<height.size();j++)
        {
            if(height[j]>=height[i])
            {
                l=j;
            }
        }
        water = max(water, (l-i)*h);
    }
    return water;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
