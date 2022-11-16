使用层序遍历，将每层的最后一个结果加入到结果数组中即可。  
```
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
    vector<int> rightSideView(TreeNode* root) {
        // 使用层序遍历，返回每次层序遍历的最后一个结点
        if (root == nullptr) return vector<int>();
        deque<TreeNode *> dq;
        dq.push_back(root);
        vector<int> res;
        while (!dq.empty()) {
            int size = dq.size();
            int temp; // 记录每层的最后一个结点的值，for 循环中每次循环都会更新它，for 循环结束后它就保存了每一层最后的值
            for (int i = 0; i < size; ++i) {
                TreeNode * t = dq.front();
                dq.pop_front();
                temp = t -> val;
                if (t -> left) dq.push_back(t -> left);
                if (t -> right) dq.push_back(t -> right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
```
