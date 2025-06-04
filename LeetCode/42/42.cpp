// 42.接雨水

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    // 双指针往中间缩比较好理解，重点是怎么缩？左右哪边小先缩哪边，不然你一边过大也没有另一面墙来接雨水
    int res = 0;
    // 当前的双指针
    int l = 0;
    int r = height.size() - 1;
    // 左、右侧的墙
    int height_l = 0;
    int height_r = 0;
    while (l < r)
    {
      height_l = max(height_l, height[l]);
      height_r = max(height_r, height[r]);
      if (height[l] < height[r])
      {
        res += max(min(height_l, height_r) - height[l], 0);
        l++;
      }
      else
      {
        res += max(min(height_l, height_r) - height[r], 0);
        r--;
      }
    }
    return res;
  }
};

int main()
{
  Solution solution;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << solution.trap(height);
  system("pause");
}