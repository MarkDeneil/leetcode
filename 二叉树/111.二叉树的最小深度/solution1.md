求二叉树的最小深度时，即求从根节点到叶子结点的最小高度，同样使用后续遍历  

递归：
不过在求的时候要注意，叶子节点是左右孩子都为 nullptr 的结点，而不能只是有一个孩子为 nullptr。利用此写终止条件的时候要注意：  
![20210203155800503](https://user-images.githubusercontent.com/83362131/204750666-713f5592-819f-4a59-8b31-9cebf31ceb80.png)  
单层逻辑是：当前结点的最小高度=左右孩子中较小的高度+1  
如果出现了上图中情况，即结点有一个孩子为 nullptr，另一个不为 nullptr，则应该返回不为 nullptr 结点的高度 + 1
```cpp
int mind(TreeNode * t) {
    // 确保 t 不为 nullptr,在主程序中判断 root 不为 nullptr
    if (t -> left == nullptr && t -> right == nullptr) return 1; // 叶子结点高度为1
    if (t -> left == nullptr && t -> right != nullptr) return mind(t -> right) + 1; 
    if (t -> left != nullptr && t-> right == nullptr ) return mind(t -> left) + 1;
    return min(mind(t -> left), mind(t -> right)) + 1;
}

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return mind(root);
    }
};
```

迭代：使用层序遍历，当有一层首先遇到叶子结点时，返回该结点的深度即为最小深度  
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
