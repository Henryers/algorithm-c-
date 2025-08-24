// 105.从前序与中序遍历序列构造二叉树

#include <iostream>
#include <algorithm>
#include <unordered_map>
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
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 先序 [root, [left, ...], [right, ...]]
        // 中序 [[left, ...], root, [right, ...]]
        // 所以关键就是：你拿到先序preorder第一个节点就是root，需对应到中序inorder中root的位置
        // 因此你才需要记录inorder中 [节点值, 索引] 这个键值对！方便按root值查找元素位置！
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return buildTreeProcess(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeProcess(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if (preL > preR)    return nullptr;
        TreeNode* root = new TreeNode(preorder[preL]);
        int inRootIndex = map[preorder[preL]];
        int leftSize = inRootIndex - inL;
        cout << "inRootIndex 到底和 preL + leftSize == inRootIndex + preL - inL 有区别 —— 错位了！（看 OneNote ）" << endl;
        cout << "inRootIndex: " << inRootIndex << endl;
        cout << "preL + leftSize: " << preL + leftSize << endl;
        cout << endl;
        root->left = buildTreeProcess(preorder, inorder, preL + 1, preL + leftSize, inL, inRootIndex - 1);
        root->right = buildTreeProcess(preorder, inorder, preL + leftSize + 1, preR, inRootIndex + 1, inR);
        return root;
    }
};

int main() {
    vector<int> preorder = { 1,2,3 };
    vector<int> inorder = { 3,2,1 };
    Solution solution;
    solution.buildTree(preorder, inorder);
    system("pause");
    return 0;
}