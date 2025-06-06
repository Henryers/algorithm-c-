// 54.螺旋矩阵

#include <iostream>
#include <vector>
#include <algorithm> // 不用会报错，但是能运行...

using namespace std;

class Solution
{
public:
  vector<int> res;
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    int l = 0, r = min(m, n);
    while (l < r)
    {
      yiquan(matrix, l, m, n);
      l++;
      r--;
    }
    if (l == r)
    {
      // 遍历一行（这一行也可能是一个）
      for (int i = l; i <= max(m, n) - l; i++)
      {
        if (m < n)
          res.push_back(matrix[l][i]);
        else
          res.push_back(matrix[i][l]);
      }
    }
    return res;
  }

  vector<int> yiquan(vector<vector<int>> &matrix, int k, int m, int n)
  {
    // m 行 n 列，从外向内第k个圈
    //  k  ... n-k   由最外层 0, n 往里缩k圈  0+k, n-k
    //  .  ...  .
    //  .  ...  .
    // m-k ...  .    由最外层 0, m 往里缩k圈  0+k, m-k
    // 下面4个循环，每次的最后一个不要遍历，留给下一个循环
    for (int i = k; i < n - k; i++)
    {
      res.push_back(matrix[k][i]);
    }
    for (int i = k; i < m - k; i++)
    {
      res.push_back(matrix[i][n - k]);
    }
    for (int i = n - k; i > k; i--)
    {
      res.push_back(matrix[m - k][i]);
    }
    for (int i = m - k; i > k; i--)
    {
      res.push_back(matrix[i][k]);
    }
    return res;
  }
};

int main()
{
  vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution solution;
  vector<int> res = solution.spiralOrder(vec);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  system("pause");
  return 0;
}