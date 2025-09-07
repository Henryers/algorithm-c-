// 84.柱状图中最大的矩形

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 类似接雨水的动态规划，感觉比单调栈好理解点
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n - 1);  // 为什么写right(n,n)？？？搞得下面左右边界条件不对称我看半天...
        // 简洁那几个变量有啥用啊！不对称看半天没看懂...
        
        // 计算left边界  left[i] 表示第i个柱子左边第一个比 heights[i] 小的柱子的位置（没有就是最左侧）
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left[p] - 1;  // 跳跃查找
            }
            left[i] = p + 1;
        }
        
        // 计算right边界  right[i] 表示第i个柱子右边第一个比 heights[i] 小的柱子的位置 + 1 （没有就是最右侧）
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) {
                p = right[p] + 1;  // 跳跃查找
            }
            right[i] = p - 1;
        }
        
        // 计算最大面积
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] + 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        
        return maxArea;
    }
};
