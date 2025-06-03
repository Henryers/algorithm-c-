// 15.三数之和

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> res;
    int N = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < N; i++){
      if (nums[i] > 0)
        break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环
      // 如果有相同的数，确保第一个数就是这串相同数的开头
      if(i > 0 && nums[i] == nums[i - 1]) continue;
      int firstnum = nums[i];
      int l = i + 1;  // 第二个数可以等于第一个数
      int r = N - 1;  // 第三个数也可能等于第一个数，但是只会出现一次，后面再缩无法得到另一种结果
      while (l < r){
        int sum = firstnum + nums[l] + nums[r];
        if(sum == 0){
          res.push_back({firstnum, nums[l], nums[r]});
          // 去重
          while(l < r && nums[l] == nums[l+1])
            l++;
          while (l < r && nums[r-1] == nums[r])
            r--;
          // 正常的 l++ r-- 操作，上面只是去重，相当于挪到当前相同数字的最后一个
          l++; // l+1 和 l 相同，也要跳过
          r--; // 同理，跳过
        }
        // 数字太小，左侧右移，换个大的试试
        else if(sum < 0)
        {
          l++;
        }
        // 数字太大，右侧左移，换个小的试试
        else{
          r--;
        }
      }
    }
    return res;
  }
};

int main(){
  Solution solution;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = solution.threeSum(nums);
  for (vector<int> item : res){
    for (int i : item){
      cout << i << " ";
    }
    cout << endl;
  }
}