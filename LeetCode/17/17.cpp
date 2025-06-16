// 17.电话号码的字母组合

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  unordered_map<char, string> map;

  vector<string> letterCombinations(string digits)
  {
    vector<string> res;
    if (digits.size() == 0)
      return res; // 别进递归！不然后面会push_back一个 "" 进去！！！
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    string tmp;
    process(res, digits, 0, tmp);
    return res;
  }

  void process(vector<string> &res, string digits, int index, string tmp)
  {
    if (index == digits.size())
    {
      res.push_back(tmp);
      return;
    }
    // 拿到现在的数字以及对应的字符串
    char digit = digits[index];
    string letters = map[digit];
    for (int i = 0; i < letters.size(); i++)
    {
      tmp += letters[i];
      process(res, digits, index + 1, tmp);
      tmp.pop_back();
    }
  }
};