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

// 在二叉搜索树中搜索，相当于：先搜索本层，再搜索左右子树（搜索其中一个即可），因此可用递归
// 参数：需要搜索的值 返回值：返回该节点或 nullptr
TreeNode * search(TreeNode * t, int val) {
    // 终止条件：如果搜索到了空节点，说明本次路径中没有该值，结束
    if (t == nullptr) return nullptr;
    if (t -> val == val) return t;

    // 单层逻辑
    if (val < t -> val) {
        return search(t -> left, val);
    } else {
        return search(t -> right, val);
    }
}

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
};
```
