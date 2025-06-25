// 75.颜色分类

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    // 省流：荷兰国旗问题
    void sortColors(vector<int> &nums)
    {
        int less = -1;
        int more = nums.size();
        int cur = 0;
        while (cur < more)
        {
            if (nums[cur] < 1) // 放到左边界下一个位置，然后右扩
            {
                swap(nums[cur], nums[++less]);
                cur++;
            }
            else if (nums[cur] > 1) // 放到右边界下一个位置，然后左扩
            {
                swap(nums[cur], nums[--more]);
                // 不能cur++，因为交换后当前数的大小仍未判定
            }
            else
            {
                cur++;
            }
        }
    }
};