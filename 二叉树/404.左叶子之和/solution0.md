从上往下判定是否为叶子，因此可以考虑 前序遍历；  
解法：前序遍历的递归+迭代  
层序遍历也可以  
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
    int sumOfLeftLeaves(TreeNode* root) {
        // 层序遍历
        int sum = 0;
        if (root == nullptr) return 0;
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            // 所有入栈的都要判空
            TreeNode * t = dq.front();
            dq.pop_front();
            if (t -> left && t -> left -> left == nullptr && t -> left -> right == nullptr) {
                sum += t -> left -> val;
            }
            if (t -> left) 
                dq.push_back(t -> left);
            if (t -> right) 
                dq.push_back(t -> right);
        }
        return sum;
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

// 前序递归
void countsum (int & sum, TreeNode * t) {
    if (t == nullptr) return;
    if (t -> left && t -> left -> left == nullptr && t -> left -> right == nullptr) {
        sum += t -> left -> val;
    }
    if (t -> left) countsum(sum, t -> left);
    if (t -> right) countsum(sum, t -> right);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        countsum(sum, root);
        return sum;
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

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // 前序递归的迭代写法
        if (root == nullptr) return 0;
        int sum = 0;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode * t = stk.top();
            stk.pop();
            if (t -> left && t -> left -> left == nullptr && t -> left -> right == nullptr) {
                sum += t -> left -> val;
            }
            if (t -> right) 
                stk.push(t -> right);
            if (t -> left)
                stk.push(t -> left);
        }
        return sum;
    }
};
```
