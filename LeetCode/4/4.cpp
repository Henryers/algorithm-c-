// 4.寻找两个正序数组的中位数

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    double res = 0;
    vector<int> nums3(nums1.size() + nums2.size()); // 不用new，需要指定大小的话后面加个括号传参就行
    int l = 0;                                      // 数组1的指针
    int r = 0;                                      // 数组2的指针
    int i = 0;                                      // 数组3的指针
    while (l != nums1.size() || r != nums2.size())
    {
      // 1. 数组2没了，或者数组1小于数组2，先加数组1
      if (r == nums2.size() || (l != nums1.size() && nums1[l] < nums2[r]))
      {
        nums3[i++] = nums1[l];
        l++;
      }
      // 2. 数组1没了，或者数组2小于数组1，先加数组2
      else if (l == nums1.size() || (r != nums2.size() && nums2[r] < nums1[l]))
      {
        nums3[i++] = nums2[r];
        r++;
      }
      // 3. 不可能两个数组都没，那就是都有，只剩下一种情况，两个数组的当前值相等
      else
      {
        nums3[i++] = nums1[l];
        nums3[i++] = nums1[l];
        l++;
        r++;
      }
    }
    for (int i = 0; i < nums3.size(); i++)
    {
      cout << nums3[i] << " ";
    }
    // 奇数
    if ((nums3.size() & 1) == 1)
    {
      res = nums3[nums3.size() / 2];
    }
    // 偶数
    else
    {
      res = (double)(nums3[nums3.size() / 2 - 1] + nums3[nums3.size() / 2]) / 2;
    }
    return res;
  }
};

int main()
{
  Solution solution;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2, 4};
  solution.findMedianSortedArrays(nums1, nums2);
  system("pause");
  return 0;
}