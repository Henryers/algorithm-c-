// 114.二叉树展开为链表

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // cur.left --变成--> cur.right
        // cur.left.最右节点 --指向--> cur.right
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left) {
                TreeNode* left = cur->left;
                TreeNode* mostRight = left;
                while (mostRight->right != nullptr) {
                    mostRight = mostRight->right;
                }
                // 准备好了就执行开始说的那两步
                mostRight->right = cur->right;
                cur->left = nullptr;
                cur->right = left;
            }
            cur = cur->right;
        }
    }
};