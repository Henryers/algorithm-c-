// 295.数据流的中位数

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin;  // 大根堆，less < 比较，大的沉在底部
    priority_queue<int, vector<int>, greater<int>> queMax;  // 小根堆，more > 比较，大的浮到顶部

    MedianFinder() {}

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {  // 1 加入大根堆
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {  // 元素个数相差两个及以上，需交换元素存放位置
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {   // 2 加入小根堆
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};
