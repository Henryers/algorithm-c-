// 1.两数之和

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> hashmap; // 使用unordered_map代替hashmap
    for (int i = 0; i < nums.size(); ++i)
    {                           // 修正循环语法
      int a = target - nums[i]; // 修正数组访问和变量名
      if (hashmap.find(a) != hashmap.end())
      {                         // 检查哈希表中是否存在
        return {hashmap[a], i}; // 返回结果
      }
      hashmap[nums[i]] = i; // 加入哈希表
    }
    return {}; // 如果没有找到，返回空vector
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = solution.twoSum(nums, target);
  for (int index : result)
  {
    cout << index << " ";
  }
  system("pause");
  return 0;
}