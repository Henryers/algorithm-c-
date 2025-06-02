// 5.最长回文子串

/**
 * 动态规划转移关系图
 * √  ?  0  0  0  0  0
 * -  √  ?  0  0  0  0
 * -  -  √  ?  0  0  0
 * -  -  -  √  ?  0  0
 * -  -  -  -  √  ?  0
 * -  -  -  -  -  √  ?
 * -  -  -  -  -  -  √
 *
 * i<j，看上三角就好
 * 对角线(i,j)是一个字母，肯定是回文子串
 * 接着是两个字母的情况，相等就是回文
 * 动态规划依赖：P(i,j) <- P(i+1, j-1) s_i == s_j，即看左下角的依赖
 * 所以你开始得初始化两排斜线，才不会出现依赖为空的情况
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    const int N = s.size();
    int res[2] = {0, 0};
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < dp.size(); i++)
    {
      dp[i][i] = 1;
      if (i != dp.size() - 1)
      {
        if (s[i] == s[i + 1])
        {
          dp[i][i + 1] = 1;
          res[0] = i;
          res[1] = i + 1;
        }
      }
    }
    // 从下往上，从左往右遍历
    // （为什么不从上往下呢？那我问你，我先在最上面遍历，是不是到第二个就依赖找不到？回答我！）
    // 为什么在外出不先从左往右，内部从下往上？那更逆天了，本来就是先i上下维度，再j左右维度的...
    for (int i = dp.size() - 3; i >= 0; i--)
    {
      for (int j = i + 2; j < dp.size(); j++)
      {
        if (dp[i + 1][j - 1] && s[i] == s[j])
        { // 左下角依赖 + 当前边缘两个字符是否相等
          dp[i][j] = 1;
          if (j - i + 1 > res[1] - res[0])
          {
            res[0] = i;
            res[1] = j;
          }
        }
      }
    }
    // 根据索引生成最终结果
    string result = "";
    for (int i = res[0]; i <= res[1]; i++)
    {
      result += s[i];
    }
    return result;
  }
};

int main()
{
  Solution solution;
  string s = "cbbd";
  string res = solution.longestPalindrome(s);
  cout << res << endl;
  system("pause");
  return 0;
}