// 236.二叉树的最近公共祖先

#include <iostream>
#include <algorithm>
#include <vector>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return left ? left : right;
    }
};

// 设置父节点写法
// class Solution {
// public:
//     unordered_map<TreeNode*, TreeNode*> fathermap;
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // 搞一个parent指针 or map? ==> 服了就是fathermap...
//         process(root);
//         TreeNode* res = root;
//         unordered_set<TreeNode*> set;  // p的祖先链条
//         TreeNode* cur = p;
//         while(cur != root){
//             set.insert(cur);
//             cur = fathermap[cur];
//         }
//         set.insert(root);
//         cur = q;
//         while(!set.count(cur)){
//             cur = fathermap[cur];
//         }
//         return cur;
//     }
//     void process(TreeNode* root){
//         if(root == nullptr) return;
//         if(root->left)  fathermap[root->left] = root;
//         if(root->right)  fathermap[root->right] = root;
//         process(root->left);
//         process(root->right);
//     }
// };