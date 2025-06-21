// 155.最小栈

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
public:
    stack<int> stk;
    stack<int> min_stk;
    MinStack()
    {
        min_stk.push(INT_MAX);
    }

    void push(int val)
    {
        stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }

    void pop()
    {
        stk.pop();
        min_stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return min_stk.top();
    }
};