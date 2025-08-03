// 24.两两交换链表中的节点

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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = head;
        ListNode *res = head->next;
        ListNode *prev = new ListNode(0);
        while (cur != nullptr && cur->next != nullptr)
        {
            // 记录2  1->3  2->1 cur->3  prev=1(1要换到2后面，和后面3-4-5-xxx对接)
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = cur;
            cur = cur->next;
            prev->next = next;
            prev = next->next;
        }
        return res;
    }
};