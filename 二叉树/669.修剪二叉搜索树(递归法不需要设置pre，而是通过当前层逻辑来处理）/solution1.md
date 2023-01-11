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
// 返回属于 [low, high] 中的节点，并让父节点指向它。注意，看到“父节点指向它”，不要立刻想保存一个 pre 记录自己的父节点。在本层逻辑中可以让本层指向下一层的返回值，就相当于写了在上一层的父节点指向本层的返回值。
// 递归不需要设置 pre 节点，而是通过本层逻辑来设置；迭代法需要设置 pre 节点
// 如果本层的值不在 [low, high] 中，那么不应该返回本层的值，而应该返回递归左右子树
// 如果本层的值在 [low, high] 中，那么先接住本层左右子树返回的值，再返回本层 root
TreeNode * cuttree(TreeNode * root, int low, int high) {
    if (root == nullptr) return nullptr;
    if (root -> val < low) {
        TreeNode * right = cuttree(root -> right, low, high);
        return right;
    }

    if (root -> val > high) {
        TreeNode * left = cuttree(root -> left, low, high);
        return left;
    }

    root -> left = cuttree(root -> left, low, high);
    root -> right = cuttree(root -> right, low, high);
    return root; // 本层值在 [low, right] 中，返回本层值
}


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode * t = cuttree(root, low, high);
        return t;
    }
};
```
