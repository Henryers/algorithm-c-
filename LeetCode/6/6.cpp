// 6.Z字形变换

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows < 2)
      return s;
    vector<string> rows(numRows);
    int i = 0, flag = -1; // 刚开始在循环里就会遇到第一次转折，反转符号变为 flag = 1
    for (char c : s)
    {
      rows[i].push_back(c);
      if (i == 0 || i == numRows - 1) // 遇到转折点，前进方向改变（到0向下，到末尾向上）
        flag = -flag;
      i += flag;
    }
    string res;
    for (const string &row : rows)
      res += row;
    return res;
  }
};

int main()
{
  Solution solution;
  string s = "PAYPALISHIRING";
  cout << solution.convert(s, 5) << endl;
  system("pause");
  return 0;
}