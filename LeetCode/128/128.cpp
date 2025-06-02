// 128.最长连续序列

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> set;
    for (int item : nums)
    {
      set.insert(item);
    }
    int longestnum = 0;
    for (int item : set)
    {
      // 查看集合中是否存在前一个元素，存在就跳出，反正我要最小的元素来组合成一条连续序列
      if (set.count(item - 1))
        continue;
      int curnum = item; // 记录当前的数字以及连续序列的个数，刚开始它作为起点，长度为1
      int lastnum = 1;
      while (set.count(curnum + 1))
      {
        curnum += 1;  // 找到下一个数字就更新成下一个数字啊（这里是数字的值，不是连续序列的个数！）
        lastnum += 1; // 这里才是连续序列的个数，只不过写法刚好和上面的相同
      }
      longestnum = lastnum > longestnum ? lastnum : longestnum;
    }
    return longestnum;
  }
};

int main()
{
  Solution solution;
  vector<int> arr = {200, 4, 100, 2, 1, 3};
  cout << solution.longestConsecutive(arr) << endl;
  system("pause");
  return 0;
}