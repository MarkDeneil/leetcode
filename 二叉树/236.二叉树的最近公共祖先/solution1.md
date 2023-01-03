最近公共祖先，思路是用后序遍历，递归函数返回 TreeNode*，如果左孩子返回了p，右孩子返回了q，那么当前节点就是最近的公共祖先。
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode * findparent(TreeNode * t, TreeNode * p, TreeNode * q) {
    if (t == nullptr) return nullptr;
    // 后序遍历，节点本身最后判断

    TreeNode * t1 = findparent(t -> left, p, q);
    TreeNode * t2 = findparent(t -> right, p, q);
    // 思想：判断逻辑是 如果递归遍历遇到q，就将q返回，遇到p 就将p返回，那么如果 左右子树的返回值都不为空，说明此时的中节点，一定是q 和p 的最近祖先。
        if (t1 && t1 != p && t1 != q) // 说明 t1 就是p、q的公共阶段 
            return t1;
        if (t2 && t2 != p && t2 != q) // 说明 t2 就是p、q的公共节点
            return t2;
        if (t1 && t2) // 因为树中所有节点都不同，所以t1 和 t2 肯定一个为p，一个为q，那么公共节点就是本届点
            return t;
        // 接下来判断这种情况：子孙节点有一个是p(q),然后自己也是p(q)
        if (t1) {
            if (t -> val != p -> val && t -> val != q -> val) {
                return t1;
            } else { // 此时 t 肯定为p 或 q，且与 t1 不同，那么 t就是公共节点
                return t;
            }
        }
        if (t2) {
            if (t -> val != p -> val && t -> val != q -> val) {
                return t2;
            } else {
                return t;
            }
        }

        // 接下来是 t1 和 t2 都为 nullptr
        if (t == p || t == q)
            return t;
        else 
            return nullptr;
            
}


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              return findparent(root, p, q);
    }
};
```
