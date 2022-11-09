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
        // 多使用了一个辅助队列
        if (root == nullptr) return vector<vector<int>>();
        deque<TreeNode *> dq; // 当前层的队列
        deque<TreeNode *> temp; // 临时存放当前层的下一层的子节点
        vector<vector<int>> res;

        dq.push_back(root); // 最初将根结点入队
        while (!dq.empty() || !temp.empty()) {
            vector<int> tempres; // 存放当前层的结果
            while (!dq.empty()) {
                TreeNode * t = dq.front();
                dq.pop_front();
                tempres.push_back(t -> val);
                if (t -> left) temp.push_back(t -> left);
                if (t -> right) temp.push_back(t -> right);
            }
            res.push_back(tempres); // 该语句不能写在下面的 if 条件内，否则最后一次的结果不会被加入到 res 中
            if (!temp.empty()) {
                while (!temp.empty()) {
                    TreeNode * h = temp.front();
                    temp.pop_front();
                    dq.push_back(h);
                }
            }
        }
        return res;
    }
};
```
