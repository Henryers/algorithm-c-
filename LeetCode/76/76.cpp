// 76.最小覆盖子串

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int count = t.size(); // 记录当前窗口还需要匹配的字符数量，最大值是子串长度，最小值为0
    // 用ASCII码记录原始子串t的词频表
    int arr[128]{};
    for (char c : t)
    {
      arr[c]++;
    }
    int l = 0, r = 0;
    int ansL = 0, minLen = INT_MAX;
    while (r < s.size())
    {
      while (count && r < s.size())
      {
        if (arr[s[r++]]-- > 0) // 这里是看减去之前，词频表是否还够，所以后置--
        {
          count--; // 有合法字符能消掉原始子串的字符就--
        }
      }

      // count<=0，说明找到了覆盖子串把原始子串都减没了
      while (!count)
      {
        if (r - l < minLen)
        {
          minLen = r - l;
          ansL = l;
        }
        if (++arr[s[l++]] > 0) // 这里是看是否真的有还回去有意义的字符（而不是多余的字符还给原始子串），所以前置++
        {
          count++;
        }
      }
    }
    return minLen == INT_MAX ? string() : s.substr(ansL, minLen);
  }
};