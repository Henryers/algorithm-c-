// 169.多数元素

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // 相消法：因为答案的数在原数组中超过一半，所以它和其他不一样的数相消之后，最后它还有剩元素！
        int consistant = nums[0];
        int times = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (consistant == nums[i])
                times++;
            else
            {
                if (times == 0)
                    consistant = nums[i];  // 全消完了，你就是新的基准
                else
                    times--;  // 没消完，那消掉吧
            }
        }
        return consistant;
    }
};