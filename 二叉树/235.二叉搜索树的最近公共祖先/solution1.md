本题可以完全按照 236.二叉树的最近公共祖先来做，但是可以利用二叉搜索树的特点更快的做出来。  
二叉搜索树特点：中序遍历，如果一个节点是p和q的祖先，那么该节点一定在[p,q]区间中
**在二叉搜索树中，从上往下递归遍历，如果遇到一个节点第一次在[p,q]中，那么该节点就是p和q的公共祖先**
利用这个特点，有两种写法，一种是不用搜索整棵树，因为是二叉搜索树，我们可以刻意地去找第一个在[p,q]中的节点，代码如下：  
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉搜索树特点：中序遍历，如果一个节点是p和q的祖先，那么该节点一定在[p,q]区间中
// 在二叉搜索树中，从上往下递归遍历，如果遇到一个节点第一次在[p,q]中，那么该节点就是p和q的公共祖先
TreeNode * findparent(TreeNode * root, TreeNode * p, TreeNode * q) {
    // 因为从上往下遍历，所以使用先序遍历
    // 终止条件：
    if (root == nullptr) 
        return nullptr;
    
    if (root -> val >= p -> val && root -> val <= q -> val) // 先序遍历，先判断根节点 
        return root;
    if (root -> val < p -> val)
        return findparent(root -> right, p, q);
    if (root -> val > q -> val) 
        return findparent(root -> left, p, q);
    return nullptr;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val < q -> val) 
            return findparent(root, p, q);
        else 
            return findparent(root, q, p);
    }
};
```
也可以搜索整棵树，这样逻辑更简单，但时间更长：
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉搜索树特点：中序遍历，如果一个节点是p和q的祖先，那么该节点一定在[p,q]区间中
// 在二叉搜索树中，从上往下递归遍历，如果遇到一个节点第一次在[p,q]中，那么该节点就是p和q的公共祖先
TreeNode * findparent(TreeNode * root, TreeNode * p, TreeNode * q) {
    // 因为从上往下遍历，所以使用先序遍历
    // 终止条件：
    if (root == nullptr) 
        return nullptr;
    
    if (root -> val >= p -> val && root -> val <= q -> val) // 先序遍历，先判断根节点 
        return root;
    TreeNode * t1 = findparent(root -> left, p, q);
    TreeNode * t2 = findparent(root -> right, p, q);
    if (t1) return t1;
    if (t2) return t2;
    return nullptr;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val < q -> val) 
            return findparent(root, p, q);
        else 
            return findparent(root, q, p);
    }
};
```
