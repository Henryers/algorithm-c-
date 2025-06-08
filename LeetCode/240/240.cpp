// 240.搜索二维矩阵

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int col = 0;
    int row = matrix.size() - 1; // 左下角为起点
    while (true)
    {
      if (matrix[row][col] > target)
      {
        row--;
      }
      else if (matrix[row][col] < target)
      {
        col++;
      }
      else if (matrix[row][col] == target)
      {
        return true;
      }
      if (row < 0 || col == matrix[0].size())
      {
        return false;
      }
    }
  }
};