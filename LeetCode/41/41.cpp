// 41.缺失的第一个正数

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    // 缺失的第一个正数，必在[1, N+1]之间，把nums的元素交换到对应位置上即可
    for (int i = 0; i < nums.size(); i++)
    {
      // 为什么用while不是if？因为你交换完一次，原来的nums[i]到了正确位置，那新的nums[i]咋办？肯定要继续找啊
      // 找不到咋办？找不到说明不在[1, N]，最后能退出循环的
      // nums[i] != nums[nums[i]-1] 这句要加上！不然两个相等的数一直在交换，跳不出来了！！！
      while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
      {
        // 必须先对nums[nums[i]-1]赋值！！！否则nums[i]变了，nums[nums[i]-1]也会跟着变！！！
        int temp = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp;
      }
    }
    for (int i = 0; i < nums.size(); i++)
    {
      if (i + 1 != nums[i])
        return i + 1;
    }
    return nums.size() + 1;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{3, 4, -1, 1};
  solution.firstMissingPositive(nums);
  system("pause");
  return 0;
}