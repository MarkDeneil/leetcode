平衡二叉树的定义为：  
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。  
注意，是高度差，因此我们要求的是节点的高度，用后序遍历求（从下往上求，左右中）  
同时单层递归的逻辑：  
先判断当前节点的左右节点是否为平衡二叉树，再判断当前结点本身是否为二叉树（即左右孩子的高度差绝对值是否大于1）  
参数和返回值：参数为当前结点指针，返回值：见具体程序分析
`int balance(TreeNode * t)`  
终止条件：当前节点为 nullptr 时，高度为0  
`if (t == nullptr) return 0`  
单层递归逻辑：  
```cpp
// 先检查左子树是否为平衡二叉树  
if (t -> left) {
  ...
}
if (t -> right) { // 检查右子树
  ...
}
// 接下来遇到问题：返回本层的高度还是返回高度差？  
// 如果返回本层的高度，那么本层逻辑中如何判断自己的左右子树是否为平衡二叉树？  
// 如果返回本层的高度差，那么可以判断左右孩子是否为平衡二叉树了（只需看它们返回的高度差），但如何判断本层的高度差？  
// 因此这样：返回 -1 代表该层不是平衡二叉树，那么只要该节点不是平衡二叉树，整个树就不是平衡二叉树了，只要把 -1 传下去即可，不用判断了；
// 若该节点是平衡二叉树，返回该层高度即可
```
整体代码如下：  
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

// 参数：当前结点
// 返回值：当前节点的高度
// 若当前节点的左右子节点的高度相差大于1，则不是平衡二叉树

int balance(TreeNode * t) { 
    if (t == nullptr) return 0; // 若当前结点为空结点，则其高度为0
    int left = balance(t -> left);
    if (left == -1) return -1; // 以 -1 表示不是平衡二叉树，在单层逻辑中，先判断左右子树本身是否为平衡二叉树，再判断当前结点是否为平衡二叉树
    int right = balance(t -> right);
    if (right == -1) return -1;
    
    // 判断当前结点是否为平衡二叉树
    if (abs(left - right) > 1) return -1;
    // 若当前结点符合平衡二叉树，返回当前节点高度
    return 1 + max(left, right);
}


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // 注意，本体不能按照求深度的思想来，是求每个结点的高度
        if (balance(root) == -1) return false;
        return true;
    }
};
```
