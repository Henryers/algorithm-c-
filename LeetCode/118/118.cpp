// 118.杨辉三角

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> tmp(i + 1, 1);
            for (int j = 1; j < numRows - 1; j++)
            {
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};