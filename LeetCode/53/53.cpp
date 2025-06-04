// 53.最大子数组和

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int res = nums[0];
    int curres = res;
    for (int i = 1; i < nums.size(); i++)
    {
      if (curres < 0)
      {
        curres = max(curres, nums[i]); // 负数就选个最小的，没必要累加
      }
      else
      {
        curres += nums[i]; // 之前是正数就累加，不必担心加了变小，因为在前一轮循环已记录最大值
      }
      res = max(res, curres);
    }
    return res;
  }
};