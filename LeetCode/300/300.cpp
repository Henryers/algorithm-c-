// 300.最长递增子序列

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                res = max(res, dp[i]);
            }
        }
        return res;

        // int len = 1, n = nums.size();
        // if (n == 0) return 0;
        // vector<int> d(n + 1, 0);
        // d[len] = nums[0];
        // for (int i = 1; i < n; ++i) {
        //     if (nums[i] > d[len]) {
        //         d[++len] = nums[i];
        //     } else {
        //         // 如果二分查找找不到，说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
        //         int l = 1, r = len, pos = 0; 
        //         while (l <= r) {
        //             int mid = (l + r) >> 1;
        //             if (d[mid] < nums[i]) {
        //                 pos = mid;
        //                 l = mid + 1;
        //             } else {
        //                 r = mid - 1;
        //             }
        //         }
        //         d[pos + 1] = nums[i];
        //     }
        // }
        // return len;
    }
};
