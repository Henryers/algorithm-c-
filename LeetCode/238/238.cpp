// 238.除自身以外数组的乘积

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    vector<int> resarr; // 我嘞个结果数组不算空间复杂度啊
    resarr.push_back(1);
    for (int i = 1; i < nums.size(); i++)
    {
      resarr.push_back(resarr[resarr.size() - 1] * nums[i - 1]);
    }
    int R = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      resarr[i] *= R;
      R *= nums[i];
    }
    return resarr;
  }
};

int main()
{
  Solution solution;
  vector<int> arr = {1, 2, 3, 4};
  solution.productExceptSelf(arr);
  system("pause");
  return 0;
}