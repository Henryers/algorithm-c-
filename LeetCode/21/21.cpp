// 21.合并两个有序链表

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *res = new ListNode(0);
    ListNode *cur = res;
    ListNode *cur1 = list1;
    ListNode *cur2 = list2;
    while (cur1 != nullptr || cur2 != nullptr)
    {
      if (!cur2 || (cur1 && cur1->val <= cur2->val))
      {
        cur->next = cur1; // 相当于头节点res的下一个是cur1节点（第一次）
        cur1 = cur1->next;
      }
      else
      {
        cur->next = cur2; // 相当于头节点res的下一个是cur2节点（第一次）
        cur2 = cur2->next;
      }
      cur = cur->next;
    }
    return res->next;
  }
};