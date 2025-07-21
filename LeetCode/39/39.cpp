// 39.组合总和

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return res;
        vector<int> path;
        dfs(candidates, 0, target, path, res);
        return res;
    }

    void dfs(vector<int>& candidates, int begin, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            path.push_back(candidates[i]); // 添加元素
            dfs(candidates, i, target - candidates[i], path, res); // 注意这里没有i+1，因为题目允许重复使用数字
            path.pop_back(); // 移除最后一个元素
        }
    }
};
