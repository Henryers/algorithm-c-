// 131.分割回文串

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> arr;
    vector<vector<int>> f;
    int n;
    vector<vector<string>> partition(string s) {
        n = s.length();
        f.assign(n, vector<int>(n, 1));
        // 真不知道之前咋想的，明明静态字符串可以先把所有情况都记录下来，就不用递归的时候一一调用了
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }
        dfs(s, 0);
        return res;
    }

    void dfs(string s, int i) {
        if (i == n) {
            res.push_back(arr);
        }
        for (int j = i; j < n; j++) {
            if (f[i][j] == 1) {
                arr.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                arr.pop_back();
            }
        }
    }
};