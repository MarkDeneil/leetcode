参考第101题  两棵子树上同时对比指针  
递归：  
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

// 返回值和参数：返回值是 bool 类型；参数：两个指针分别指向两个树，每次比较两个树的同一位置的结点
bool check(TreeNode * t1, TreeNode * t2) {
    // 终止条件：两个指针指向的结点本身不同；或结点值不同 则返回 false
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr && t2 != nullptr) return false;
    if (t1 != nullptr && t2 == nullptr) return false;
    // 两个结点本身相同，接下来判定节点值是否相同
    if (t1 -> val != t2 -> val)
        return false;
    // 程序执行到这里说明两个指针的值都相同了，接下来只需对比左右孩子的对称情况了，左右孩子都对称，那么两颗树对称，否则两棵树不对称
    return check(t1 -> left, t2 -> left) && check(t1 -> right, t2 -> right);
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 递归
        return check(p, q);
    }
};
```
迭代：  
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

// 返回值和参数：返回值是 bool 类型；参数：两个指针分别指向两个树，每次比较两个树的同一位置的结点

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 迭代
        deque<TreeNode *> dq;
        dq.push_back(p);
        dq.push_back(q);
        while (!dq.empty()) {
            TreeNode * t1 = dq.front();
            dq.pop_front();
            TreeNode * t2 = dq.front();
            dq.pop_front();
            if ((t1 == nullptr && t2 != nullptr) || (t1 != nullptr && t2 == nullptr)) return false;
            if (t1 != nullptr && t2 != nullptr) {
                if (t1 -> val != t2 -> val) return false;
                dq.push_back(t1 -> left);
                dq. push_back(t2 -> left);
                dq.push_back(t1 -> right);
                dq.push_back(t2 -> right);
            }
        }
        return true;
    }
};
```
