思路和 106.根据中序遍历和后续遍历构造二叉树 和 105.根据前序遍历和后序遍历构造二叉树 一样  
根据最大值的下标来划分数组  
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

// 返回值：返回本层根节点 参数：每一层的不重复的整数数组 nums 
TreeNode * maxtree(vector<int> nums) {
    if (nums.empty()) {
        return nullptr;
    }

    int max = -1;
    int maxindex = -1;
    int index = -1;
    for (auto x : nums) {
        ++index;
        if (x > max) {
            maxindex = index;
            max = x;
        }
    }
    vector<int> leftnums(nums.begin(), nums.begin() + maxindex);
    vector<int> rightnums(nums.begin() + maxindex + 1, nums.end());
    TreeNode * t = new TreeNode(max, maxtree(leftnums), maxtree(rightnums));
    return t;
}
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maxtree(nums);
    }
};
```
