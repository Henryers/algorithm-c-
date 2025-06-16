// 78.子集

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> inner;
  vector<vector<int>> res;

  vector<vector<int>> subsets(vector<int> &nums)
  {
    int n = nums.size();
    // 不用像全排列那样管顺序，而是应该考虑每个元素选或者不选，共2^n种情况
    for (int i = 0; i < (1 << n); i++)
    {
      inner.clear();
      bool flag = true;
      // 把当前的数当作二进制来看，看1/0决定是否添加元素
      for (int j = 0; j < n; j++)
      {
        if ((i & (1 << j)) != 0)
        {
          inner.push_back(nums[j]);
        }
      }
      res.push_back(inner);
    }
    return res;
  }
};