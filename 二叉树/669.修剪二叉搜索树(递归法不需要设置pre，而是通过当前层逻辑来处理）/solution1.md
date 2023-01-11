注意本题思路：如果一个节点属于 \[low, high] 中，就向上层返回该节点，如果一个节点不属于 \[low, high]，就返回递归子己左右子树中属于 \[low, high] 中的节点，否则返回 nullptr  
之前的一个错误的思路是：如果一个节点不在 \[low, high] 中，就返回它的左右子树中属于 \[low, high] 的递归，这种思路是不好写的.
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
// 思路：如果一个节点属于 [low, high] 中，就向上层返回该节点，如果一个节点不属于 [low, high]，就返回递归子己左右子树中属于 [low, high] 中的节点，否则返回 nullptr
// 如果父节点接收到了非 nullptr ，就要指向它。
// 注意，不是返回要删除的节点，如果一个节点要被删除（不属于[low, high] 中），则它先返回左右子树中属于[low, high] 中的值（即递归左右子树），否则就返回nullptr
// 如果一个父亲节点接收到了 nullptr，说明这个子树分支没有在 [low, high] 中的节点，则零该分支为 nullptr

// 注意，看到“父节点指向它”，不要立刻想保存一个 pre 记录自己的父节点。在本层逻辑中可以让本层指向下一层的返回值，就相当于写了在上一层的父节点指向本层的返回值。
// 递归不需要设置 pre 节点，而是通过本层逻辑来设置；迭代法需要设置 pre 节点

TreeNode * cuttree(TreeNode * cur, int low, int high) {
    if (cur == nullptr) return nullptr;
    if (cur -> val > high) {
        return cuttree(cur -> left, low, high);
    }
    if (cur -> val < low) {
        return cuttree(cur -> right, low, high);
    }
    TreeNode * left = cuttree(cur -> left, low, high);
    TreeNode * right = cuttree(cur -> right, low, high);
    if (left) 
        cur -> left = left;
    else 
        cur -> left = nullptr;
    if (right) 
        cur -> right = right;
    else 
        cur -> right = nullptr;
    return cur;
}


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode * t = cuttree(root, low, high);
        return t;
    }
};
```


