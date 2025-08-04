// 239.滑动窗口最大值

/**
 * onenote 上有逐步图解案例
 */

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
      // 确保单调递减队列，队列中比当前nums[i]小的元素将被淘汰！
      while (!deque.empty() && nums[deque.back()] < nums[i])
      {
        deque.pop_back();
      }
      // 添加当前元素
      deque.push_back(i);
      // 单调队列可能满了，k+1那么大，最前面的元素要去除哦
      if (deque.front() == i - k)
      {
        deque.pop_front();
      }
      // 窗口形成后，记录答案
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