这题一开始做错了，**做错的原因是用递归时，简单地认为：只要左右子树都是二叉搜索树，再判断本层是否符合二叉搜索树的条件，就可以判断该树是否为二叉搜索树了。**  
**我们要比较的是 左子树所有节点小于中间节点，右子树所有节点大于中间节点。**  
下面这种情况是反例：  
![20200812191501419](https://user-images.githubusercontent.com/83362131/209529923-12715a9b-3adc-4303-bdaf-5d82280f3526.png)  
因此根据上面这个逻辑写出的代码是错误的。  
解题的思路是：  
**中序遍历下，输出的二叉搜索树节点的数值是有序序列。**  
因此可以在递归时维护一个保存所有中序访问过的节点值的数组，每次按照中序遍历访问新节点时，新结点的值应该比数组最后一个值大。  
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

// 递归：二叉搜索树的中序遍历是由小至大的数组
// 参数：一个 vector，存着中序遍历时访问的数组的值，以及 TreeNode 节点
// 返回值：bool 返回值，一旦检测到不是二叉搜索树，则返回 false
bool checkbin(vector<int> & vec, TreeNode * t) {
    if (t == nullptr) return true;

    if (checkbin(vec, t -> left) == false) return false;

    if (!vec.empty()) {
        if (t -> val <= vec.back()) return false; // 中序遍历访问，访问过程中当前节点的值应该始终比已经访问的所有节点的值大
    }
    vec.push_back(t -> val); // 注意，不应该回溯，因为当前节点的值应该比所有已经访问过的节点的值大

    if (checkbin(vec, t -> right) == false) return false;
    return true;
}


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        return checkbin(vec, root);
    }
};
```
