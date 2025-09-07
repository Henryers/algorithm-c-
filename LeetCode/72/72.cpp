// 72.编辑距离

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.length() + 1;
        int col = word2.length() + 1;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        // 一行一列初始化，当成其中一个word是空串，零一个通过插入的方式与之匹配
        for (int i = 1; i < row; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j < col; j++) {
            dp[0][j] = j;
        }
        // 先考虑对角线的是否替换，再考虑横竖两个相邻的元素，分别代表插入删除
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
        }
        return dp[row - 1][col - 1];
    }
};