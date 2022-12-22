与 106.从中序遍历与后序遍历构造二叉树 解法一样  
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

TreeNode * construct(vector<int> preorder, vector<int> inorder) {
    if (inorder.empty()) {
        return nullptr;
    }
    if (inorder.size() == 1) {
        TreeNode * t = new TreeNode(preorder[0], nullptr, nullptr);
        return t;
    }
    int rootval = preorder[0];
    int index = -1;
    for (auto x : inorder) {
        ++index;
        if (x == rootval) {
            break;
        }
    }
    vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
    vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());

    preorder.erase(preorder.begin());
    vector<int> leftpreorder(preorder.begin(), preorder.begin() + leftinorder.size());
    vector<int> rightpreorder(preorder.begin() + leftinorder.size(), preorder.end());

    TreeNode * t = new TreeNode(rootval, construct(leftpreorder, leftinorder), construct(rightpreorder, rightinorder));
    return t;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder, inorder);
    }
};
```
