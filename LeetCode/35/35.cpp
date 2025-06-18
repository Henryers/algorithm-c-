// 35.搜索插入位置

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int res = 0;
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (nums[mid] < target)
      {
        l = mid + 1;
      }
      else if (nums[mid] > target)
      {
        r = mid - 1;
      }
      else
      {
        return mid;
      }
    }
    return l;
  }
};