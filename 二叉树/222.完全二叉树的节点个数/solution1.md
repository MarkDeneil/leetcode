可以直接用深度优先、广度优先遍历求解，但还可以利用二叉树的性质：（参考代码随想录）  
完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满。  
对于情况一，可以直接用 2^树深度 - 1 来计算，注意这里根节点深度为1。  
对于情况二，分别递归左孩子，和右孩子，递归到某一深度一定会有左孩子或者右孩子为满二叉树，然后依然可以按照情况1来计算。  
![20201124092543662](https://user-images.githubusercontent.com/83362131/204297471-b71fc278-669c-4b9a-9b77-864ed8e42838.png)  
![20201124092634138](https://user-images.githubusercontent.com/83362131/204297515-c3b39c79-5bd2-4550-a077-7938db0c5f5d.png)  
在完全二叉树中，如果递归向左遍历的深度等于递归向右遍历的深度，那说明就是满二叉树。  
判断其子树岂不是满二叉树，如果是则利用用公式计算这个子树（满二叉树）的节点数量，如果不是则继续递归  
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

int count(TreeNode * t) {
    if (t == nullptr) return 0;
    TreeNode * l = t -> left;
    TreeNode * r = t -> right;
    int depthl = 0, depthr = 0;
    while (l) {
        ++depthl;
        l = l -> left;
    }
    while (r) {
        ++depthr;
        r = r -> right;
    }
    if (depthr == depthl) { // 说明是满二叉树，可以直接按照公式计算
        return pow(2, depthl + 1) - 1;
    }
    return count(t -> left) + count(t -> right) + 1; // 说明不是满二叉树，不能按照公式计算
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        return count(root);
    }
};
```
