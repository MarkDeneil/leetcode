理解合并二叉树的递归思想：  
先合并本层的根节点，再合并本层的左右子树  
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

// 递归：先合并节点本身，再合并左右子树
// 参数和返回值：函数返回合并后的节点；
TreeNode * merge(TreeNode * root1, TreeNode * root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return nullptr;
    } else if (root1 == nullptr) {
        return root2;
    } else if (root2 == nullptr) {
        return root1;
    }

    int val = root1 -> val + root2 -> val;
    TreeNode * t = new TreeNode(val, merge(root1 -> left, root2 -> left), merge(root1 -> right, root2 -> right));
    return t;
}

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};
```
使用层序遍历做，需要好好思考一下条件设置，并且将合并两个树种的某一个树作为主树操作，返回时返回该主树  
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


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 迭代，层序遍历
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        deque<TreeNode *> dq1;
        deque<TreeNode *> dq2;

        TreeNode * t1 = root1;
        TreeNode * t2 = root2;

        dq1.push_back(t1);
        dq2.push_back(t2);

        while (!dq1.empty() && !dq2.empty()) {
            TreeNode * t1 = dq1.front();
            dq1.pop_front();
            TreeNode * t2 = dq2.front();
            dq2.pop_front();

            // 空节点不入队列，所以不考虑下列判断
            // if (t1 == nullptr && t2 == nullptr) {}

            t1 -> val += t2 -> val;
            if (t1 -> left == nullptr && t2 -> left == nullptr) {
                // 什么都不需要做
            } else if (t1 -> left == nullptr) {
                t1 -> left = t2 -> left;
            } else if (t2 -> left == nullptr) {
                // 什么都不需要做，因为本来就是以 t1 为生成后的树
            } else { // t1 -> left 和 t2 -> left 都不是空节点，才入队列
                dq1.push_back(t1 -> left); 
                dq2.push_back(t2 -> left);
            }

            if (t1 -> right == nullptr && t2 -> right == nullptr) {
                // 什么都不需要做
            } else if (t1 -> right == nullptr) {
                t1 -> right = t2 -> right;
            } else if (t2 -> right == nullptr) {
                // 什么都不需要做
            } else { // t1 -> right 和 t2 -> right 都不空是菜入队列
                dq1.push_back(t1 -> right);
                dq2.push_back(t2 -> right);
            }
        }
        return t1;
    }
};
```
