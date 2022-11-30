首先要注意深度和高度的区别：  
二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）  
二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数后者节点数（取决于高度从0开始还是从1开始）  

递归：  
使用前序遍历可以求深度（因为从上往下求深度），使用后序遍历可以求一个结点的高度（因为高度从下往上求一个结点的高度）  
在本题中，二叉树的最大深度=根节点的高度，所以我们可以使用后续遍历来求根节点的高度，即求出了二叉树的最大深度  
总体思路是根节点的高度为0；一个结点的高度等于左右孩子结点较大的高度+1；  
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


int depth(TreeNode * t) {
    if (t ==nullptr) return 0;
    int left = depth(t -> left); // 左
    int right = depth(t -> right); // 右
    return 1 + max(left, right); // 中
} 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};
```
迭代：  
迭代可以使用层序遍历
