// 148.排序链表

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

class Solution {
public:
    // 归并排序思路（合并时操作指针比较容易）
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* mid = getMiddle(head);
        ListNode* midNext = mid->next;  // 右侧链表的起始点
        mid->next = nullptr;  // 链表要断掉啊！不然还有奇奇怪怪的关联！
        ListNode* left = sortList(head);
        ListNode* right = sortList(midNext);
        return merge(left, right);
    }

    // 快慢指针，找链表中间节点，将列表分成两半
    ListNode* getMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // 归并操作
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left != nullptr)
            cur->next = left;
        if (right != nullptr)
            cur->next = right;
        return dummy->next;
    }
};