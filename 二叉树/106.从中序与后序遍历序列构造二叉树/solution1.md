// 按照下标来差分  
// 重点是拆分后序遍历时，时候拆分后的 leftinroder 数组的大小来拆分！
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

// 采用下标来拆分
// 拆分中序遍历：根据后序遍历的最后一个元素来拆分
// 拆分后序遍历：去掉最后一个元素后，后序遍历前半部分是根节点左边的节点，后半部分是根节点右边的节点
// 后序遍历中根节点左边的节点的数量与拆分中序遍历后拆得的左数组的数量相同！！！
TreeNode * construct(vector<int> inorder, vector<int> postorder) {
    if (postorder.size() == 0) return nullptr;
    if (postorder.size() == 1) {
        TreeNode * t = new TreeNode (postorder[0]);
        return t;
    }
    int rootval = postorder[postorder.size() - 1];
    int index = -1; // 中序遍历中 rootval 的下标
    for (auto x : inorder) {
        ++index;
        if (x == rootval) {
            break;
        }
    }
    vector<int> leftinorder(inorder.begin(), inorder.begin() + index); // inorder.begin() + index 这个迭代器指向的数并没有被拷贝到 leftinorder 中,因为该迭代器指向的元素就是 rootval 本身
    vector<int> rightinorder(inorder.begin() + index + 1, inorder.end()); // inorder.begin() + index 这个迭代器指向的数也不应该被拷贝到 leftinorder 中,因为该迭代器指向的元素就是 rootval 本身

    postorder.erase(postorder.end() - 1); // 删除最后一个本层根节点数据

    // 这里拆分后序遍历时的重要思想：遍历中根节点左边的节点的数量与拆分中序遍历后拆得的左数组的数量相同！！！
    vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size()); // postorder.begin() + leftinorder.size() 这个元素本身应该属于 rightpostorder
    vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end());

    TreeNode * t = new TreeNode(rootval);
    t -> left = construct(leftinorder, leftpostorder);
    t -> right = construct(rightinorder, rightpostorder);
    return t;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return construct(inorder, postorder);
    }
};
```
