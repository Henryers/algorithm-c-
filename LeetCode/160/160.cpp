// 160.相交链表

#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if (headA == nullptr || headB == nullptr)
      return nullptr;
    ListNode *pA = headA;
    ListNode *pB = headB;
    while (pA != pB) // 要么相等为相交节点，要么最后都为nullptr
    {
      pA = pA == nullptr ? headB : pA->next; // A B 都遍历一遍，长度最后就相等了（对齐）
      pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
  }
};