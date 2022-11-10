与二叉树的层序遍历相同，只不过用到一个辅助栈来反转输出即可。  
也可以使用`reverse(res.begin(), res.end());`来反转输出。  
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        deque<TreeNode *> dq;
        stack<vector<int>> stk; // 因为要自底向上层序遍历，因此用辅助栈
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> tempres; // 记录当前层的结点值
            for (int i = 0; i < size; ++i) {
                TreeNode * t = dq.front();
                dq.pop_front();
                tempres.push_back(t -> val);
                if (t -> left) dq.push_back(t -> left);
                if (t -> right) dq.push_back(t -> right);
            }
            stk.push(tempres);
        }
        while (!stk.empty()) {
            vector<int> tempres = stk.top();
            stk.pop();
            res.push_back(tempres);
        }
        return res;
    }
};
```
