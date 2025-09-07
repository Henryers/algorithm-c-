// 51.N皇后

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int N;
    vector<int> position;  // 记录皇后在所有行中的列位置
    vector<bool> column;  // 列约束
    vector<bool> left;  // 左约束
    vector<bool> right; // 右约束
    vector<vector<string>> res;  // 结果

public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        position.assign(N, 0);  // 0没放，1放了皇后
        column.assign(N, true);  // 当前都可以填，三种约束都true，即没约束
        left.assign(2 * N - 1, true);
        right.assign(2 * N - 1, true);
        putQueen(0);  // 从第一行开始填
        return res;
    }

    void putQueen(int row) {
        for (int col = 0; col < N; col++) {
            // 如果当前可放皇后
            if (column[col] && left[row + col] && right[row - col + N - 1]) {
                // 1 记位置+约束
                position[row] = col;  // 回溯时不用清除，你下一次填的col不一致会直接覆盖该行的值的！（天然行约束）
                column[col] = false;
                left[row + col] = false;
                right[row - col + N - 1] = false;
                // 2 进递归填下一行（填完记录情况加res里）
                if (row < N - 1) {
                    putQueen(row + 1);
                }
                else {
                    vector<string> smallres;
                    for (int i = 0; i < N; i++) {
                        string str(N, '.');
                        str[position[i]] = 'Q';
                        smallres.push_back(str);
                    }
                    res.push_back(smallres);
                }
                // 3 出递归除去约束
                column[col] = true;
                left[row + col] = true;
                right[row - col + N - 1] = true;
            }
        }
    }
};