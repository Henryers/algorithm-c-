// 48.旋转图像

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int l = 0;
    int r = n - 1 - l;
    while (l < n / 2)
    {
      int dt = 0; // 偏移量
      while (dt < r - l)
      {
        int tmp = matrix[l][l + dt];
        // 螺旋填好
        matrix[l][l + dt] = matrix[r - dt][l]; // 左下 --填到--> 左上
        matrix[r - dt][l] = matrix[r][r - dt]; // 右下 --填到--> 左下
        matrix[r][r - dt] = matrix[l + dt][r]; // 右上 --填到--> 右下
        matrix[l + dt][r] = tmp;               // 左上 --填到--> 右上
        dt++;
      }
      l++;
      r--;
    }
  };
};

int main(){
  Solution solution;
  vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  solution.rotate(arr);
  for(int i = 0; i < arr.size(); i++){
    for(int j = 0; j < arr.size(); j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  system("pause");
  return 0;
}