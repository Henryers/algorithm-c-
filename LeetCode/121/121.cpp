// 121.买卖股票的最佳时机

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int res = 0;
        int r = 1;
        int min = prices[0];
        // 不可能出现之前的大数-当前min的情况，只可能当前数-之前的min进行更新（符合题意）
        while (r < prices.size())
        {
            if (prices[r] > min)
                res = max(res, prices[r] - min);
            else
                min = prices[r];
            r++;
        }
        return res;
    }
};