// 438.找到字符串中所有字母异位词

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        vector<int> goal(26);
        vector<int> mytry(26);
        for (int i = 0; i < p.size(); i++)
        {
            goal[p[i] - 'a']++;
            mytry[s[i] - 'a']++;
        }
        if (goal == mytry)
            res.push_back(0);
        for (int i = 1; i <= s.size() - p.size(); i++)
        {
            mytry[s[i + p.size() - 1] - 'a']++;
            mytry[s[i - 1] - 'a']--;
            if (goal == mytry)
                res.push_back(i);
        }
        return res;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution solution;
    vector<int> res = solution.findAnagrams(s, p);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}