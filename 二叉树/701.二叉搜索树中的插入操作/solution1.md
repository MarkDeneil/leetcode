思路:可以画一个二叉树模拟一下，其实只需要按照需要插入的值在二叉树中一直找，知道遇到空节点，就在空节点处插入就可以。  
按照这种思想可以很方便的写出迭代法：  
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 顺着节点的值一直往下找，直到找到空节点，就在该位置插入该值即可
        if (root == nullptr) {
            TreeNode * t = new TreeNode(val);
            return t;
        }

        TreeNode * pre = nullptr;
        TreeNode * cur = root;
        while (cur != nullptr) {
            pre = cur;
            if (cur -> val > val) 
                cur = cur -> left;
            else if (cur -> val < val)
                cur = cur -> right;
            else {

            }
        }
        // 循环结束后，cur 的位置就是应该插入的位置，pre 是其父节点，比较 pre -> val 和 val 的值，判定应该插到 pre 的左子树还是 pre 的右子树
        if (pre -> val > val) {
            TreeNode * t = new TreeNode(val);
            pre -> left = t;
        }
        else if (pre -> val < val) {
            TreeNode * t = new TreeNode(val);
            pre -> right = t;
        }
        else{

        }
        return root;
    }
};
```
递归法：  
本题递归法的难点是如何设计递归函数原型。可以考虑这样：  
终止条件：如果遇到了需要插入值的空节点的位置，就构造一个插入值节点并返回，让其父节点接入这个返回的节点。因此返回值可以设计为 TreeNode*。  
那么当前层的递归逻辑是：如果左右孩子返回了一个不为 nullptr 的节点，则说明左右孩子处就是构造要插入节点的位置，那么就让左右孩子指针指向它们返回的节点。  
否则，返回空节点，说明未找到。  
需要注意的是，一但找到了要插入节点的位置并且插入完毕，父节点也是要返回 nullptr 的，否则父节点的父节点还会继续构造。  
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
// 递归思路：按照二叉树的值往下搜索，遇到 nullptr 就说明需要在这个地方插入节点了，构建一个新节点返回给父节点
// 父节点判定收到了非空节点，就插入该非空节点。
// 注意，插入操作后，父节点仍然返回 nullptr 节点。否则父节点的上层还要插入
TreeNode * insert(TreeNode * root, int val) {
    // 终止条件：遇到了空节点，该节点就是要插入的地方
    if (root == nullptr) {
        TreeNode * t = new TreeNode(val);
        return t;
    }
    
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
    if (root -> val < val) {
        right = insert(root -> right, val);
    } else if (root -> val > val) {
        left = insert(root -> left, val);
    } else{

    }

    if (left != nullptr) { // left 接住了root左孩子返回的不为空的节点，那么应该在 root -> left 插入该节点
        root -> left = left;
        return nullptr; // 注意，插入操作后，父节点仍然返回 nullptr 节点。否则父节点的上层还要插入

    }
    if (right != nullptr) {
        root -> right = right;
        return nullptr;
    }
    return nullptr;
}
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode * t = new TreeNode(val);
            return t;
        }
        insert(root, val);
        return root;
    }
};
```
