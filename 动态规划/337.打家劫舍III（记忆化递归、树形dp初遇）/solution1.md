本题可以使用递归方法，二叉树题目一定要先想遍历方式，前中后（递归）+层序。本题使用后序遍历，因为需要用到函数的返回值做下一步计算。  
偷了本节点，就不考虑两个孩子节点；不偷本节点，就可以考虑偷两个孩子节点，递归如下：  
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
int robb(TreeNode * root) {
    if (root == nullptr) 
        return 0;
    int res1 = 0, res2 = 0;
    // 盗窃根节点
    res1 += root -> val;
    if (root -> left) res1 += robb(root -> left -> left) + robb(root -> left -> right);
    if (root -> right) res1 += robb(root -> right -> left) + robb(root -> right -> right);
    // 不盗窃根节点
    res2 += robb(root -> left) + robb(root -> right);
    return max(res1, res2);
    
}

class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        return robb(root);
    }
};

```
上述方法会超时，可以使用记忆化递归，将已经求过的解记录下来（因为记忆化递归要用于所有的递归程序，不难想象它是一个全局变量或在参数中以引用的形式出现）：  
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
int robb(TreeNode * root, unordered_map<TreeNode *, int> & m) {
    if (root == nullptr) 
        return 0;
    if (m.find(root) != m.end()) // 记忆化搜索
        return m[root];
    int res1 = 0, res2 = 0;
    // 盗窃根节点
    res1 += root -> val;
    if (root -> left) res1 += robb(root -> left -> left, m) + robb(root -> left -> right, m);
    if (root -> right) res1 += robb(root -> right -> left, m) + robb(root -> right -> right, m);
    // 不盗窃根节点
    res2 += robb(root -> left, m) + robb(root -> right, m);
    m.insert(make_pair(root, max(res1, res2))); // 不需要判定是否插入过了，对于同一个节点每次插入的结果一定是相同的，所以只需要插入第一次即可
    return max(res1, res2);
    
}

class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        unordered_map<TreeNode *, int> m;
        return robb(root, m);
    }
};
```
树形 dp 方法：   
二叉树题目，仍然以二叉树递归框架来阶梯（使用后序遍历）  
dp数组（dp table）以及下标的含义：下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱。
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

// 我们要求一个节点 偷与不偷的两个状态所得到的金钱，那么返回值就是一个长度为2的数组。
// dp数组（dp table）以及下标的含义：下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱。

vector<int> robb(TreeNode * root) {
    vector<int> dp(2,0);
    if (root == nullptr)
        return dp; 
    
    vector<int> left = robb(root -> left);
    vector<int> right = robb(root -> right);
    // 若偷当前节点，则不能偷左右孩子节点
    dp[1] = root -> val + left[0] + right[0];

    // 不偷当前节点，则可以选择偷孩子节点，但是不一定偷，取 偷与不偷孩子节点的较大者
    dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
    return dp;
}

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = robb(root);
        return max(res[0], res[1]);
    }
};
```

