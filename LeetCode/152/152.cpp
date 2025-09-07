// 152.乘积最大子数组

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            long mx = maxF, mn = minF;  // 下面第一条窜改会影响第二条代码，所以先记录
            maxF = max(mx * nums[i], max((long)nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min((long)nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};