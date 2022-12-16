递归函数返回值确定思路：  
再来看返回值，递归函数什么时候需要返回值？什么时候不需要返回值？这里总结如下三点：
- 如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。（这种情况就是本文下半部分介绍的113.路径总和ii）  
- 如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。 （这种情况我们在236. 二叉树的最近公共祖先(opens new window)中介绍）  
- 如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。（本题的情况）  
本题中是搜索树中一条符合条件的路径，因此递归一定需要返回值，返回值设置为 bool 类型，遇到了符合条件的路径就要及时返回 true  
此外，本题的终止条件也是判断叶子结点，那么：  
**因为终止条件是判断叶子节点，所以递归的过程中就不要让空节点进入递归了**。  
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

bool countsum(int & cursum, int & target, TreeNode * t) {
    // 终止条件：遇到叶子结点并计算
    // 因为终止条件是判断叶子节点，所以递归的过程中就不要让空节点进入递归了
    cursum += t -> val;
    if (t -> left == nullptr && t -> right == nullptr) {
        if (cursum == target) return true;
        return false;
    }

    if (t -> left) {
        bool tag = countsum(cursum, target, t -> left);
        if (tag == true) return true; // 不能在这里使用 return countsum(cursum, target, t -> left); 因为如果该函数返回 false，本层函数不应该直接返回false，而应该还继续判断右分支
        cursum -= t -> left -> val;
        
    }
    if (t -> right) {
        bool tag = countsum(cursum, target, t -> right);
        if (tag == true) return true;
        cursum -= t -> right -> val;
        
    }
    return false;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 根节点到叶子节点-》从上往下-》前序遍历
        if (root == nullptr) return false;
        int cursum = 0;
        return countsum(cursum, targetSum, root);
    }
};
```
