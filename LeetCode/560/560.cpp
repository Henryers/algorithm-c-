// 560.和为 K 的子数组

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    // x x x [x x x x] 括号里合为k
    // [x x x] x x x x 等价于这里前缀和为pre-k，所以在前缀和累加时要记录 pre-k以及出现的次数
    int res = 0;
    int pre = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
      pre += nums[i];
      if (map.find(pre - k) != map.end())
      {
        res += map[pre - k];
      }
      map[pre] = map[pre] ? map[pre] + 1 : 1;
    }
    return res;
  }
};