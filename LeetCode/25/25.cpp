// 25.K 个一组翻转链表

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
    // 太远的farnext全局记录一下
    ListNode* farnext = nullptr;
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 在T24（两个一组翻转链表）的基础上，把翻转操作封装成函数就行
        if(!judge(head, k)) return head;
        ListNode* prev = new ListNode(0);
        ListNode* res = prev;
        ListNode* cur = head;
        while(judge(cur, k)){
            prev-> next = reverse(cur, k);
            prev = cur;
            cur = cur->next;
        }
        return res->next;
    }

    bool judge(ListNode* head, int k){
        ListNode* cur = head;
        while(k--){
            if(cur == nullptr) return false;
            cur = cur->next;
        }
        // 记录远处的next节点
        farnext = cur;
        return true;
    }

    ListNode* reverse(ListNode* head, int k){
        // 在这里获取远处的next节点
        ListNode* prev = farnext;
        ListNode* cur = head;
        while(k--){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution solution;
    head = solution.reverseKGroup(head, 3);
    cout << head->val << head->next->val << head->next->next->val << head->next->next->next->val << head->next->next->next->next->val;
    system("pause");
    return 0;
}