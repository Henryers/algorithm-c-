// 22.括号生成

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }

    void dfs(string tmp, int restl, int restr) {
        if (restl > restr) return;
        if (restl == 0) {
            for (int i = 0; i < restr; i++) {
                tmp += ')';
            }
            res.push_back(tmp);
            return;
        }
        tmp += '(';
        dfs(tmp, restl - 1, restr);
        tmp.pop_back();
        if (restl < restr) {
            tmp += ')';
            dfs(tmp, restl, restr - 1);
            tmp.pop_back();
        }
    }
};
