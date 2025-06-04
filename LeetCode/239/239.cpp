// 239.滑动窗口最大值

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    vector<int> res;
    deque<int> deque;
    for (int i = 0; i < nums.size(); i++)
    {
      // 窗口右侧的值太小，去掉，
      while (!deque.empty() && nums[deque.back()] <= nums[i])
      {
        deque.pop_back();
      }
      // 没事，这次就算不是最大的也加上去，
      // 一是你不在这里加要在哪加？二是下一次循环时，它作为窗口最后一个不合格的元素也会被去掉！
      deque.push_back(i);
      // 再弹出左侧的节点   i-k [i-k+1, i]
      if (deque.front() <= i - k)
        deque.pop_front();
      // 窗口形成后，加答案
      if (i >= k - 1)
      {
        res.push_back(nums[deque.front()]);
      }
    }
    return res;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {7, 2, 4};
  vector<int> res = solution.maxSlidingWindow(nums, 2);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  system("pause");
  return 0;
}