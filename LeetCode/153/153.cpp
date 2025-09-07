// 153.寻找旋转排序数组中的最小值

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            // nums[l] > nums[mid] 思路错误，你这样比左边，如果l==mid还得判断
            if (nums[mid] < nums[r]) {  // 思路正确，mid一直是偏小的，不会和r重合，两个元素时判断有效，还可以往左边缩！
                // 左边是含有最小值的
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};