
首先要注意深度和高度的区别：  
二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）  
二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数后者节点数（取决于高度从0开始还是从1开始）  

递归：  
使用前序遍历可以求深度（因为从上往下求深度），使用后序遍历可以求一个结点的高度（因为高度从下往上求一个结点的高度）  
在本题中，二叉树的最大深度=根节点的高度，所以我们可以使用后续遍历来求根节点的高度，即求出了二叉树的最大深度  
总体思路是根节点的高度为0；一个结点的高度等于左右孩子结点较大的高度+1；   

此外，本题中的终止条件是判断叶子结点，因此：
**因为终止条件是判断叶子节点，所以递归的过程中就不要让空节点进入递归了。**  
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

求最大深度，深度是从上往下求，原本的逻辑应该使用前序遍历+回溯
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

// 最大深度，从上往下计算，应该用前序，递归 + 回溯
void reversaldepth(TreeNode * t, int & depth, int & res) {
    if (t -> left == nullptr && t -> right == nullptr) return ; // 注意，如果利用判断是否为叶节点来终止，那么单层逻辑中应该防止空结点进入递归
    // 终止条件是判断叶子节点，所以递归的过程中就不要让空节点进入递归了
    if (t -> left) {
        ++depth;
        if (depth > res) res = depth;
        reversaldepth(t -> left, depth, res);
        --depth;
    }

    if (t -> right) {
        ++depth;
        if (depth > res) res = depth;
        reversaldepth(t -> right, depth, res);
        --depth;
    }
    return ;

} 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 1;
        int depth = 1;
        reversaldepth(root, depth, res);
        return res;
    }
};
```

迭代：  
迭代可以使用层序遍历
