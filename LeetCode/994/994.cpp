// 994.腐烂的橘子

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    queue<pair<int, int>> q; // 动态记录当前层新感染点的队列
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m = grid.size(), n = grid[0].size();
    int cnt = 0; // 新鲜橘子的数量
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 2) // 找到第一轮腐烂橘子
          q.push({i, j});
        else if (grid[i][j] == 1)
          cnt++;
    if (q.empty() && cnt) // 如果没有腐烂橘子并且有新鲜橘子，则新鲜橘子不可能腐烂
      return -1;
    int ans = 0;
    // bfs，每次弹出上一层的所有感染坐标点，再加入当前层所有新感染点
    while (!q.empty())
    {
      int t = q.size(); // 遍历同一时间感染的橘子
      for (int k = 0; k < t; k++)
      {
        pair<int, int> p = q.front();
        q.pop();
        for (auto dir : dirs)
        {
          int x = p.first + dir[0];
          int y = p.second + dir[1];
          if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) // 找到新感染的橘子
          {
            grid[x][y] = 2; // 放心改原数组，反正后面就是要这样依赖（不知一开始为啥还加个dp...）
            q.push({x, y});
            cnt--;
          }
        }
      }
      if (!q.empty()) // 如果当前轮有新感染的橘子，时间加一
        ans++;
    }
    if (cnt) // 如果还有没被感染的新鲜橘子
      return -1;
    return ans;
  }
};
