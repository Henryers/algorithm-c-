// 189.轮转数组

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int N = nums.size();
    k = k % N;
    myswap(nums, 0, N - 1);
    myswap(nums, 0, k - 1);
    myswap(nums, k, N - 1);
  }

  void myswap(vector<int> &nums, int l, int r)
  {
    while (l < r)
    {
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
  }
};