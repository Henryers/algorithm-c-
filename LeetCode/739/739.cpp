// 739.每日温度

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 0; i < n; i++){
            // 单调栈，弹出来的时候才更新，类似于等待温度高的天数来唤醒之前的天
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int prevIndex = s.top();
                res[prevIndex] = i - prevIndex;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};