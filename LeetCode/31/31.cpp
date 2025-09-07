// 31.下一个排列

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        // 从右往左第一次降序的位置
        int firstLess = -1;
        for(int i = N - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                firstLess = i;
                break;
            }
        }
        // 4321 -> 1234 reverse
        if(firstLess < 0){
            reverse(nums, 0, N-1);
        }else{
            int right = -1;
            for(int i = N-1; i > firstLess; i--){
                if(nums[i] > nums[firstLess]){
                    right = i;
                    break;
                }
            }
            swap(nums[firstLess], nums[right]);
            reverse(nums, firstLess + 1, N - 1);
        }
    }

    void reverse(vector<int>& nums, int l, int r){
        while(l < r){
            swap(nums[l++], nums[r--]);
        }
    }
};