// 138.随机链表的复制

using namespace std;
#include <iostream>
#include <algorithm>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* cur = head;
        // 新链表每个元素都加在原始链表后面（交叉排列），建立关系后等下random才好分配处理
        while(cur != nullptr){
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;  // 跳两次是因为复制的newNode挂在cur后面了
        }
        cur = head;  // 回到起点
        // random指向配置
        while(cur != nullptr){
            cur->next->random = cur->random == nullptr ? nullptr : cur->random->next;  // 得加next，不然指向原链表了
            cur = cur->next->next;
        }
        cur = head;  // 回到起点
        Node* res = head->next;
        // 新链表的抽离
        while(cur != nullptr){
            Node* newnode = cur->next;
            cur->next = cur->next->next;
            // newnode->next = newnode->next->next;  // 第一个循环就指向了第四个节点？不对，如果第三个节点为空，那就直接nullptr
            newnode->next = newnode->next == nullptr ? nullptr : newnode->next->next;
            cur = cur->next;
        }
        return res;
    }
};