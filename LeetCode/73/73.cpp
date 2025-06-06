// 73.矩阵置零

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    unordered_set<int> rows;
    unordered_set<int> cols;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};