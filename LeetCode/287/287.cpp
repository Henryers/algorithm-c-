// 287.寻找重复数

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        // 快慢指针，快指针一次走2步，慢指针1步
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        // 相遇后都共同走一步，知道类似环形链表那样相遇！
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};