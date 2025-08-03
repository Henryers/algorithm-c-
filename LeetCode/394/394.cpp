// 394.字符串解码

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int I = 0;
    string decodeString(string s) {
        string res = "";
        string tmp = "";
        while(I < s.size()){
            // 遇到数字就进子问题
            if(s[I] >= '0' && s[I] <= '9'){
                res += getSubString(s);  // I在递归中会更新，最后停在右括号的位置
            }
            else {
                res += s[I];
            }
            I++;
        }
        return res;
    }

    // 5[xxx] 这种格式
    string getSubString(string &s){
        string res = "";
        string tmp = "";
        // repeat 这个数字可能是几位数，而不是一直是个位数！！！
        int repeat = 0;
        int count = 0;
        while(isdigit(s[I])){
            repeat = repeat * 10 + (s[I]-'0');
            I++;
        }
        I++;  // 跳过'['
        while(s[I] != ']'){
            // 遇到数字就进子问题
            if(s[I] >= '0' && s[I] <= '9'){
                tmp += getSubString(s);
            }
            // 正常就直接加
            else {
                tmp += s[I];
            }
            I++;
        }
        // I++; // 跳出来时停在']'位置，所以要跳过~
        // 是时候，清算一切！！！
        for(int j = 0; j < repeat; j++){
            res += tmp;
        }
        return res;
    }
};

int main(){
    string s = "3[a]2[bc]";
    Solution solution;
    string res = solution.decodeString(s);
    cout << res;
    system("pause");
    return 0;
}