// 46.全排列

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> res;
  vector<int> tmp;
  vector<int> visited;
  vector<vector<int>> permute(vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      visited.push_back(0);
    }
    process(nums, 0, tmp); // 从第0个位置开始填
    return res;
  }

  void process(vector<int> &nums, int i, vector<int> tmp)
  {
    if (i == nums.size())
    {
      res.push_back(tmp);
      return;
    }
    for (int k = 0; k < nums.size(); k++)
    {
      if (visited[k] == 0)
      {
        tmp.push_back(nums[k]);
        visited[k] = 1;
        process(nums, i + 1, tmp);
        tmp.pop_back();
        visited[k] = 0;
      }
    }
  }
};