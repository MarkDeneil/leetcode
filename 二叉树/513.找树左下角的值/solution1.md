第一种方法是层序遍历，遍历到最后一层记录第一个叶子结点的值  
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
    int findBottomLeftValue(TreeNode* root) {
        // 层序遍历，找到最底层的第一个结点，如何判断最底层？
        // 拿一个 vector 记录每一层的数据，遍历结束后 vector 中的第一个值即是
        deque<TreeNode *> dq;
        vector<int> vec;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            vec.clear();
            for (int i = 0; i < size; ++i) {
                TreeNode * t = dq.front();
                dq.pop_front();
                vec.push_back(t -> val);
                if (t -> left) dq.push_back(t -> left);
                if (t -> right) dq.push_back(t -> right);
            }
        }
        return vec[0];
    }
};
```
第二种方法是递归法，即找“最大深度的叶子节点的值”，因为要找第一个左下角的叶子结点，因此使用前序遍历，这个过程中需要回溯，两种写法：  
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

// 递归函数的参数分别为深度参数，最大深度，最大深度叶子结点的值，以及树节点

void maxdepth(int & depth, int & maxdepthval, int & val, TreeNode * t) {
    ++depth;
    int curdepth = depth;
    if (t -> left == nullptr && t -> right == nullptr) {
           if (curdepth > maxdepthval) { // 注意，这里不能是等于，因为要寻找最左边的叶子节点
                maxdepthval = curdepth;
                val = t -> val;
                return;
           }
    }
    if (t -> left) {
        maxdepth(depth, maxdepthval, val, t -> left);
        --depth;
    }
    if (t -> right) {
        maxdepth(depth, maxdepthval, val, t-> right);
        --depth;
    }

}

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // 递归，找深度最大的叶子结点
        // 最大深度，从上往下，使用前序
        // 同时记录深度和深度最大的叶子结点值，并实时变更
        int depth = 0;
        int maxdepthval = -1;
        int val = -1;
        maxdepth(depth, maxdepthval, val, root);
        return val;
    }
};
```
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

// 递归函数的参数分别为深度参数，最大深度，最大深度叶子结点的值，以及树节点

void maxdepth(int & depth, int & maxdepthval, int & val, TreeNode * t) {
    int curdepth = depth;
    if (t -> left == nullptr && t -> right == nullptr) {
           if (curdepth > maxdepthval) { // 注意，这里不能是等于，因为要寻找最左边的叶子节点
                maxdepthval = curdepth;
                val = t -> val;
                return;
           }
    }
    if (t -> left) {
        ++depth;
        maxdepth(depth, maxdepthval, val, t -> left);
        --depth;
    }
    if (t -> right) {
        ++depth;
        maxdepth(depth, maxdepthval, val, t-> right);
        --depth;
    }

}

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // 递归，找深度最大的叶子结点
        // 最大深度，从上往下，使用前序
        // 同时记录深度和深度最大的叶子结点值，并实时变更
        int depth = 1;
        int maxdepthval = -1;
        int val = -1;
        maxdepth(depth, maxdepthval, val, root);
        return val;
    }
};
```
