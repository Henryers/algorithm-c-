// 283.移动零

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    // 双指针
    // 快指针记录当前移动的位置，慢指针记录多少个非0元素的位置
    // 比如我当前遍历了12个数，前面有7个非0，5个0，那么下次遇到非0的数时，就把这个数填到第8位上
    int fast = 0;
    int slow = 0;
    while (fast < nums.size())
    {
      int num = nums[fast];
      if (num != 0)
      {
        nums[slow] = num;
        slow++;
      }
      fast++;
    }
    // 快指针完了，慢指针后的应该都变为0
    fill(nums.begin() + slow, nums.end(), 0); // fill 批量填充更快
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {0, 1, 0, 2, 3};
  solution.moveZeroes(nums);
  for (int item : nums)
  {
    cout << item << " ";
  }
  cout << endl;
  system("pause");
  return 0;
}