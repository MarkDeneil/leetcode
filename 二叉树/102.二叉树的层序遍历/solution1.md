第一次尝试多使用了一个辅助队列，因为在遍历当前层时，如果用 while 循环判断队列是否为空来判定当前层的迭代是否结束，那么当前层队列中元素的孩子元素就不能直接放入该当前层队列中，要构造一个辅助队列。
实际上，只需要记录一下当前层元素的个数 size，每一轮迭代都迭代 size 次即可。  
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size(); // 计算本层结点数，即本轮迭代的次数，并将本轮迭代的每个节点的值放入 vector<int> 中，作为最终结果的一组结果
            vector<int> tempres;
            for (int i = 0; i < size; ++i) {
                TreeNode * t = dq.front();
                dq.pop_front();
                tempres.push_back(t -> val);
                if (t -> left) dq.push_back(t -> left);
                if (t -> right) dq.push_back(t -> right);
            }
            res.push_back(tempres);
        }
        return res;
    }
};
```
