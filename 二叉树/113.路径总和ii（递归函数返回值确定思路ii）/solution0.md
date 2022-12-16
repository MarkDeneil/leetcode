递归函数返回值确定思路：  
再来看返回值，递归函数什么时候需要返回值？什么时候不需要返回值？这里总结如下三点：  
- 如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。（这种情况就是本文下半部分介绍的113.路径总和ii）  
- 如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。 （这种情况我们在236. 二叉树的最近公共祖先(opens new window)中介绍）  
- 如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。（本题的情况）  
本题是要搜索整个二叉树且不需要处理递归返回值，递归函数就不要返回值  
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

// 参数 path 记录路径，如果路径一旦符合，则加入该路径到 res 中；因此 path 也需要回溯

void countsum(vector<vector<int>> &res, vector<int> &path, int &cursum, int &target, TreeNode * t) {
    
    cursum += t -> val;
    path.push_back(t -> val);
    if (t -> left == nullptr && t -> right == nullptr) {
        if (cursum == target) {
            res.push_back(path);
        }
    }

    if (t -> left) {
        countsum(res, path, cursum, target, t -> left);
        cursum -= t -> left -> val;
        path.pop_back(); // path 根据进入的结点不同实时变化，也需要回溯
    }

    if (t -> right) {
        countsum(res, path, cursum, target, t -> right);
        cursum -= t -> right -> val;
        path.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // 根节点到叶子节点-》前序遍历
        if (root == nullptr) return vector<vector<int>>();
        vector<int> path;
        vector<vector<int>> res;
        int cursum = 0;
        countsum(res, path, cursum, targetSum, root);
        return res;
    }
};
```
