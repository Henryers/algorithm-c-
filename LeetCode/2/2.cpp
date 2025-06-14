// 2.两数相加
// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

#include <iostream>

using namespace std;

// Definition for singly-linked list.
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    int add = 0;
    while (l1 != nullptr || l2 != nullptr || add == 1)
    {
      int a = l1 ? l1->val : 0;
      int b = l2 ? l2->val : 0;
      int res = (a + b + add) % 10;
      add = (a + b + add) / 10;
      cur->next = new ListNode(res);
      cur = cur->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    return dummy->next;
  }
};
