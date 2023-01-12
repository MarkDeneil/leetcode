整体思路：先根据二叉搜索树构造一个有序数组，然后中序遍历树，遍历第一个节点时，值应该是整个数组的和，遍历第二个节点时，值应该是（包括）第二个元素之后数组的和...  
因为题目要求每个节点 node 的新值等于原树中大于或等于 node.val 的值之和，且该树是二叉搜索树，那么自然想到二叉搜索树中序遍历的节点值是递增的这个性质。  
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

// 整体思路：先根据二叉搜索树构造一个有序数组，然后中序遍历树，遍历第一个节点时，值应该是整个数组的和，遍历第二个节点时，值应该是（包括）第二个元素之后数组的和...
static int x = 0;

void resettree(TreeNode * root, vector<int> vec) {
    if (root == nullptr) return;
    resettree(root -> left, vec);
    int size = vec.size();
    int sum = 0;
    for (int i = x; i < vec.size(); ++i)
        sum += vec[i];
    root -> val = sum;
    ++ x;
    resettree(root -> right, vec);
    return;
}

void createnum(TreeNode * root, vector<int> & vec) {
    // 中序遍历二叉搜索树，构造有序数组
    if (root == nullptr) return;
    createnum(root -> left, vec);
    vec.push_back(root -> val);
    createnum(root -> right, vec);
    return;
}


class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> vec;
        createnum(root, vec);
        x = 0; // 定义 static 变量
        resettree(root, vec);
        return root;

    }
};
