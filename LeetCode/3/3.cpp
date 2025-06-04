// 3.无重复字符的最长子串

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<char, int> map;
    int l = 0;
    int r = 0;
    int res = 0;
    while (r < s.size())
    {
      if (map.find(s[r]) != map.end())
      {
        // 找到重复字符？如果在左边界里面就更新左边界，否则无需更新
        // x b x [ x x x b ] 上一个在左边界的左侧，也就是左侧之外，无需更新
        // x x x [ x b x b ] 这次就要更新了： x x x x b [ x b ]
        l = max(map[s[r]] + 1, l);
      }
      map[s[r]] = r;
      res = max(res, r - l + 1);
      r++;
    }
    return res;
  }
};