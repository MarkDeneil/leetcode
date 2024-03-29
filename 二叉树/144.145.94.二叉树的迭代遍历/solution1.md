中序遍历的迭代遍历比较麻烦：  
具体见官方题解。  
```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode * cur = root;
        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur -> left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur -> val);
            cur = cur -> right;
        }
        return res;
    }
};
```
前序遍历迭代较简单：  
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            TreeNode * cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            if (cur -> right != nullptr) stk.push(cur -> right); // 右子树先入栈，这样左子树的值先出栈，才符合前序遍历
            if (cur -> left != nullptr) stk.push(cur -> left); 
        }
        return res;
    }
};
```
后序遍历迭代思想：
![393A631D843B09930F368042335AD548](https://user-images.githubusercontent.com/83362131/203576431-0070fda7-980a-457a-813b-80eab92b62ab.png)  
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            TreeNode * cur = stk.top();
            if (cur -> right != nullptr) {
                stk.push(cur -> right);
                cur -> right = nullptr; // 必须将已经入栈的左右孩子结点赋为 nullptr ，否则会陷入无限循环
            }
            if (cur -> left != nullptr) {
                stk.push(cur -> left);
                cur -> left = nullptr;
            }
            cur = stk.top();
            if (cur -> left == nullptr && cur -> right == nullptr) {
                res.push_back(cur -> val);
                stk.pop();
            }
        }
        return res;
    }
};
```
