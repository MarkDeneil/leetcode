递归  
1. 确定递归函数的参数和返回值 因为我们要比较的是根节点的两个子树是否是相互翻转的，进而判断这个树是不是对称树，所以要比较的是两个树，参数自然也是左子树节点和右子树节点。返回值自然是bool类型。  
2. 确定终止条件
3. 单词递归逻辑
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

bool check(TreeNode * l, TreeNode * r) {
    if (!l && !r) return true; // 两个指针都指向 nullptr 时，因为两个指针是镜像走的，说明对称
    if (!l || !r) return false; // 若 (!l || !r) 成立，则两个指针中有一个指向 nullptr（因为两个指针同时指向 nullptr 在第一个 if 
                                // 考虑过了，两个指针都不指向 nullptr 时，不会进入此分支
    // 1. 判定结点值是否对称 2. 判定结点本身是否对称
    return (l -> val == r -> val) && check(l -> left, r -> right) && check (l -> right, r -> left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 递归
        // 我们可以实现这样一个递归函数，通过「同步移动」两个指针的方法来遍历这棵树，pp 指针和 qq 指针一开始都指向这棵树的根，随后 pp 右移时，qq 左移，pp 左移时，qq 右移。每次检查当前 pp 和 qq 节点的值是否相等，如果相等再判断左右子树是否对称。
    if (root == nullptr) return true;
    return check(root -> left, root -> right);
    }
};
```

迭代：
首先我们引入一个队列，这是把递归程序改写成迭代程序的常用方法。初始化时我们把根节点入队两次。每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像），然后将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。  
```
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
    bool isSymmetric(TreeNode* root) {
        // 迭代：左右子结点对称的插入队列中，那么队列中相邻的两个结点应该是相同的
        // 关于插入 nullptr 的问题，只要当前的指针不为空，就插入其左右孩子，这样不会引起空指针引用问题
        // 如果当前左右两个指针一个为空，一个不为空，则不对称
        if (root == nullptr) return true;
        deque<TreeNode *> dq;
        dq.push_back(root);
        dq.push_back(root); // 根节点插入两次
        while (!dq.empty()) {
            TreeNode * t1 = dq.front();
            dq.pop_front();
            TreeNode * t2 = dq.front();
            dq.pop_front();
            if ((t1 == nullptr && t2 != nullptr) || (t1 != nullptr && t2 == nullptr)) return false; // 检查结点本身位置是否对称
            if (t1 != nullptr && t2 != nullptr) {
                if (t1 -> val != t2 -> val) return false; 
                dq.push_back(t1 -> left);
                dq. push_back(t2 -> right);
                dq.push_back(t1 -> right);
                dq.push_back(t2 -> left);
            }
        }
        return true;
    }
};
```
