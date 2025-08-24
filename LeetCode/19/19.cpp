// 19.删除链表的倒数第 N 个结点

#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    // if (head->next == nullptr)
    //   return nullptr;
    // int count = 0;
    // ListNode *cur = head;
    // ListNode *dummy = new ListNode(0);
    // dummy->next = head;
    // while (cur != nullptr)
    // {
    //   count++;
    //   cur = cur->next;
    // }
    // int target = count - n;
    // cur = dummy;
    // while (target--)
    // {
    //   cur = cur->next;
    // }
    // cur->next = cur->next->next;
    // return dummy->next;

    // 双指针一次遍历不香吗？
    ListNode* res = head;
    ListNode* p = head;
    ListNode* q = head;
    int count = n;
    while (count--) {
      p = p->next;
    }
    if (p == nullptr) return res->next; // 删除的是头节点
    while (p->next != nullptr) {
      p = p->next;
      q = q->next;
    }
    // 需要严谨的话，删除节点的next也要指向nullptr
    // ListNode* next = q->next;
    q->next = q->next->next;
    // next->next = nullptr;
    return res;
  }
};