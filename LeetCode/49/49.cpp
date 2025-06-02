// 49.字母异位词分组

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); i++)
    {
      string s = strs[i];
      sort(s.begin(), s.end()); // 对字符串进行排序
      string sortedStr = s;     // 排序后的字符串
      if (map.find(sortedStr) != map.end())
      {
        map[sortedStr].push_back(strs[i]); // 如果键存在，添加原始字符串到对应的向量
      }
      else
      {
        map[sortedStr] = {strs[i]}; // 如果键不存在，创建新的向量并添加原始字符串
      }
    }
    vector<vector<string>> result; // 用于存储最终结果的向量
    for (auto &pair : map)
    { // 遍历map，提取所有的值
      result.push_back(pair.second);
    }
    return result;
  }
};