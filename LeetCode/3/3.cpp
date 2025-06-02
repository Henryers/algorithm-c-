// 3.无重复字符的最长子串

#include <iostream>
#include <string>
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
        l = map[s[r]] + 1 > l ? map[s[r]] + 1 : l;
      }
      map[s.at(r)] = r;
      res = res > r - l + 1 ? res : r - l + 1;
      r++;
    }
    return res;
  }
};