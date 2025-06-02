// 7.整数反转

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    if (x == INT32_MIN)
      return 0;                // Java下文可以直接abs，这里调用原始方法会有个特例要单独判断
    int flag = x > 0 ? 1 : -1; // 1 正数  2 负数
    int res = 0;
    int absx = x > 0 ? x : -x;
    while (absx > 0)
    {
      int tmp = absx % 10;
      // 再添加最后一位之前做越界判断  int [-2147483648, 2147483647]
      // 原先如果10位数，最高位只能是 1 or 2，所以这里直接判断当前res就行
      if (res > 214748364)
        return 0;
      res = res * 10 + tmp;
      absx /= 10;
    }
    return flag * res;
  }
};

int main()
{
  Solution solution;
  cout << solution.reverse(123) << endl;
  system("pause");
  return 0;
}