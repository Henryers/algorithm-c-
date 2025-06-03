// 11.盛最多水的容器

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int res = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r)
    {
      int area = min(height[l], height[r]) * (r - l);
      res = max(res, area);
      // 哪边矮先缩哪边
      if (height[l] < height[r])
      {
        l++;
      }
      else
      {
        r--;
      }
    }
    return res;
  }
};