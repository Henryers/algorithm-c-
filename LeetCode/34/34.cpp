// 34.在排序数组中查找元素的第一个和最后一个位置

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int l = 0;
    int r = nums.size() - 1;
    int first = -1;
    int last = -1;
    // 找第一个等于target的位置
    while (l <= r)
    {
      int middle = (l + r) >> 1;
      if (nums[middle] == target)
      {
        first = middle;
        r = middle - 1; // 重点：以first左边的元素作为右边界，继续寻找更小的索引
      }
      else if (nums[middle] > target)
      {
        r = middle - 1;
      }
      else
      {
        l = middle + 1;
      }
    }

    // 最后一个等于target的位置
    l = 0;
    r = nums.size() - 1;
    while (l <= r)
    {
      int middle = (l + r) >> 1;
      if (nums[middle] == target)
      {
        last = middle;
        l = middle + 1; // 重点：以last右边的元素作为左边界，继续寻找更大的索引
      }
      else if (nums[middle] > target)
      {
        r = middle - 1;
      }
      else
      {
        l = middle + 1;
      }
    }
    return vector<int>{first, last};
  }
};