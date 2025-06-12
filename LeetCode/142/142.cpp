// 142.环形链表Ⅱ

#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    if (head == nullptr)
      return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    do
    { // 强制动一次，不然一直移动不了！！！（直接退出了！）
      if (fast == nullptr || fast->next == nullptr)
        return nullptr;
      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);
    slow = head; // 为什么这样操作呢？
    // 慢指针走x，快指针走2x，两者相差的x就是环的一圈
    // 所以你把慢指针走到入环之前那段补到一圈中缺少的那部分，发现这两部分长度是相同的？！
    while (fast != slow)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};