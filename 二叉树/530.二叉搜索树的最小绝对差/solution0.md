本题还是用 98.验证二叉搜索树 同样的思想：  
**中序遍历下，二叉搜索树是一个有序递增数组**  
因此，树中任意两节点的最小差就是按照中序遍历二叉搜索树，后一个节点减去前一个节点的最小差  
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

void findmin(TreeNode * t, vector<int> & vec, int & res) {
    // 终止条件：当遇到空节点
    if (t == nullptr) return ;
    findmin(t -> left, vec, res);
    if (!vec.empty()) { // 注意，在计算第一个节点时，vec 为空的，此时不用计算
        if (t -> val - vec.back() < res) res = t -> val - vec.back();
    }
    vec.push_back(t -> val);
    findmin(t -> right, vec, res);
}


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        // 利用中序遍历下二叉搜索树返回递增的数组这一性质，只需计算中序遍历时当前节点和上一节点差值的最小值

        int res = 100001;
        vector<int> vec;
        findmin(root, vec, res);
        return res;
    }
};
```
