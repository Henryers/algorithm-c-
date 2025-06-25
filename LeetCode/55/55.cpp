// 55.跳跃游戏

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == farthest)
                return false;
        }
        return true;
    }
};