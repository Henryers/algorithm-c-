// 74.搜索二维矩阵

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    vector<int> firstcol;
    for (int i = 0; i < matrix.size(); i++)
    {
      firstcol.push_back(matrix[i][0]);
    }
    int row = searchInsert(firstcol, target);
    if (row == -1)
      return false;
    int col = searchInsert(matrix[row], target);
    if (col == -1)
      return false;
    // 看看当前值是不是答案，是就是，不是就不是
    if (col == matrix[0].size())
      return false;
    return matrix[row][col] == target;
  }

  // T35，一维数组找值（改进版，因为要找的数不是最）
  // return r  偏小target的情况，如果数组中没有比target小的元素，会越界
  // 为什么要找偏小？因为这样你找出来的行才是正确的啊！行后面的数都更大，答案可能在里面
  // 越界啥情况？当你target比开头第一个最小的数还小，那没救了，肯定越界找不到，直接false
  int searchInsert(vector<int> &nums, int target)
  {
    int res = 0;
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (nums[mid] < target)
      {
        l = mid + 1;
      }
      else if (nums[mid] > target)
      {
        r = mid - 1;
      }
      else
      {
        return mid;
      }
    }
    return r; // 处理 target 比所有数都小的情况
  }
};

int main()
{
  vector<vector<int>> vec = {{1}, {3}};
  Solution solution;
  cout << solution.searchMatrix(vec, 3);
  system("pause");
  return 0;
}
