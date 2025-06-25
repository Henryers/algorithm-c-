// 45.跳跃游戏 II

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        // 题目保证肯定能跳到最后一位，因此最后一位不用遍历
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]); // 更新速度始终在跳数之前
            if (i == currentEnd)
            {
                jumps++; // 当前跳数增加，能跳到的最远距离就是前面更新的farthest
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};