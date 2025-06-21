// 20.有效的括号

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<int> stack;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stack.push('(');
			}
			else if (s[i] == '[')
			{
				stack.push('[');
			}
			else if (s[i] == '{')
			{
				stack.push('{');
			}
			else if (s[i] == ')' && (stack.empty() || stack.top() != '('))
			{
				return false;
			}
			else if (s[i] == ']' && (stack.empty() || stack.top() != '('))
			{
				return false;
			}
			else if (s[i] == '}' && (stack.empty() || stack.top() != '('))
			{
				return false;
			}
			else
			{
				stack.pop();
			}
		}
		return stack.empty();
	}
};