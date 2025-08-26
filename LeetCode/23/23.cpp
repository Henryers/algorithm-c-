// 23.合并 K 个升序链表

#include <iostream>
#include <algorithm>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return lists[l];
        int mid = (l + r) / 2;
        ListNode* left = merge(lists, l, mid);
        ListNode* right = merge(lists, mid + 1, r);
        return merge2Lists(left, right);
    }

    // T21 合并两个有序链表
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;
        ListNode* left = list1;
        ListNode* right = list2;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            }
            else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left != nullptr) {  // 代码多点，但可以直接拼接上去，复杂度O(min(m,n))
            cur->next = left;
        }
        else {
            cur->next = right;
        }
        return res->next;
    }
};