层序遍历  
注意，当一个结点的左右孩子都为空时，这个结点才是叶子结点  
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
    int minDepth(TreeNode* root) {
        // 仍然采用层序遍历，如果遇到了队列中哪个结点的左右子结点任一个为空，结束遍历返回高度
        deque<TreeNode *> dq;
        if (root == nullptr) return 0;
        dq.push_back(root);
        int depth = 0;
        while (!dq.empty()) {
            ++depth;
            int size = dq.size();
            for (int i = 0; i < size; ++i) {
                TreeNode * t = dq.front();
                dq.pop_front();
                // 叶子结点：自己不为空，左右子节点都为空
                if (t -> left == nullptr && t -> right == nullptr) return depth;
                if (t -> left) dq.push_back(t -> left);
                if (t -> right) dq.push_back(t -> right);
            }
        }
        return depth;
    }
};
```
