思路：递归法构造二叉树的思路  
有序数组转换为高度平衡的二叉搜索树，有序数组的中间节点可以作为二叉搜索树的根节点，因此产生构造思路：
对于一个给定的数组，采取中间节点作为根节点，再划分数组，并递归构造左右子树,同时，这样构造的树也是平衡二叉树
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
 // 要求构造平衡二叉搜索树：去数组中间元素构建根节点，再递归构造左右子树；返回值返回当前构造的节点
 // 因此要切分数组
 TreeNode * createtree(vector<int> nums) {
     if (nums.size() == 0) return nullptr;
     int size = nums.size();
     int mid = size / 2; // 下标 mid 是数组中间元素或者数组中间靠右一个元素
     TreeNode * root = new TreeNode(nums[mid]);
     vector<int> left(nums.begin(), nums.begin() + mid);
     vector<int> right(nums.begin() + mid + 1, nums.end());
     root -> left = createtree(left);
     root -> right = createtree(right);
     return root;


 }
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createtree(nums);
    }
};
```
