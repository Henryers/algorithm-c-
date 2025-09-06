// 79.单词搜索

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        int rows = board.size();
        int cols = board[0].size();
        // 初始化 visited 矩阵
        visited.assign(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && word.length() == 1) {
                    return true;
                }
                else if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    res = process(board, i, j, word, 1); // 当前位置[i][j]已经匹配上，需要找下一个和单词word[1]匹配的位置
                    if (res) return true;
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }

    bool process(vector<vector<char>>& board, int i, int j, string word, int k) {
        if (k == word.length()) return true;
        for (int d = 0; d < 4; d++) {
            int next_i = i + direction[d][0];
            int next_j = j + direction[d][1];
            if (next_i < 0 || next_i >= board.size() || next_j < 0
                || next_j >= board[0].size() || visited[next_i][next_j]) continue;
            if (board[next_i][next_j] == word[k]) {
                visited[next_i][next_j] = true;
                bool res = process(board, next_i, next_j, word, k + 1);
                if (res) return true;
                visited[next_i][next_j] = false;
            }
        }
        return false;
    }
};