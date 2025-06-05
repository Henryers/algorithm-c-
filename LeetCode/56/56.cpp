// 56.合并区间

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  // 自定义比较器类
  // struct Compare {
  //     bool operator()(vector<int> a, vector <int> b) const {
  //         return a[0] < b[0]; // 升序比较
  //     }
  // };

  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    // 先按数组的第一个元素排序
    sort(intervals.begin(), intervals.end()); // 没有比较器！因为C++默认二维数组就是比较第一个元素大小
    // C++: Java，这波是我赢了...
    // 先把第一个数组加进去，后面在循环中，数组就可以与前一个进行比较，来看看是否需要合并区间
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] <= res[res.size() - 1][1] && intervals[i][1] > res[res.size() - 1][1])
      {
        res[res.size() - 1][1] = intervals[i][1];
      }
      else if (intervals[i][0] > res[res.size() - 1][1])
      {
        res.push_back(intervals[i]);
      }
    }
    return res;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> res = solution.merge(arr);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i][0] << " " << res[i][1] << "      ";
  }
  cout << endl;
  system("pause");
  return 0;
}