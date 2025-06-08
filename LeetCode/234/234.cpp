// 234.回文链表

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
  bool isPalindrome(ListNode *head)
  {
    ListNode *fast = head;
    ListNode *slow = head;
    if (head->next == nullptr)
      return true;
    // 如果节点数是单数，那么最后的fast停留在最后一个节点，slow停在正中间节点
    // 如果节点数是双数，那么最后的fast停留在最后一个节点后的空指针，slow停在中间偏右节点（刚好是后半段链表的开头）
    while (fast != nullptr && fast->next != nullptr)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    // 单数    1-2-3-2-1  慢指针下一个置空  1-2-3 2-1  那得反转前半段
    // 3-2-1 2-1    跳过中间节点    2-1  2-1
    if (fast != nullptr)
    {
      ListNode *righthead = slow->next;
      slow->next = nullptr;                   // 分开，前半段反转
      ListNode *lefthead = reverseList(head); // 前半段的新头节点
      lefthead = lefthead->next;              // 跳过中间节点
      // 比较
      while (lefthead != nullptr)
      {
        if (lefthead->val != righthead->val)
          return false;
        lefthead = lefthead->next;
        righthead = righthead->next;
      }
    }
    // 双数  1-2-2-1  慢指针置空   1-2-2  1
    // 那得反转后半段，慢指针不能置空，而是应该直接当成后半段的开始并反转后半段链表
    else
    {
      ListNode *righthead = reverseList(slow);
      // 比较
      while (righthead != nullptr)
      {
        if (head->val != righthead->val)
          return false;
        righthead = righthead->next;
        head = head->next;
      }
    }
    return true;
  }

  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur != nullptr)
    {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev; // cur都空了，肯定返回前一个啊
  }
};

int main()
{
  Solution solution;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(1);
  bool res = solution.isPalindrome(head);
  if (res)
    cout << 1;
  else
    cout << 0;
  system("pause");
  return 0;
}