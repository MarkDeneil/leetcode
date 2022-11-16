翻转二叉树的思想：  
我们从根节点开始，递归地对树进行遍历，并从叶子节点先开始翻转。如果当前遍历到的节点 root 的左右两棵子树都已经翻转，那么我们只需要交换两棵子树的位置，即可完成以 root 为根节点的整棵子树的翻转  
翻转二叉树可以用递归和迭代两种方法来解决。  
使用迭代法解决？即遍历各各个结点，每遇到一个结点就翻转它的子树。  
递归法：
递归三部曲：
1. 返回值和参数：参数肯定要有当前要反转的结点，返回值不需要有  
2. 终止条件：当当前结点为 nullptr 的时候，说明已经不需要翻转了（到叶子节点了）；注意，当当前结点不为空，两个子结点都为空或有一个为空时，仍然要翻转。  
3. 每层递归的逻辑：需要翻转 1）当前结点的左右子树本身 2）对左右子结点再调用该递归函数进行翻转  
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

void reverse(TreeNode * t) 
{
    if (t == nullptr) return ;
    // 我们从根节点开始，递归地对树进行遍历，并从叶子节点先开始翻转。如果当前遍历到的节点 rootroot 的左右两棵子树都已经翻转，那么我们只需要交换两棵子树的位置，即可完成以 rootroot 为根节点的整棵子树的翻转
    // 先翻转左、右子树，再翻转当前结点的左右分支，反之亦可
    // 递归三部曲：返回值和参数：无需返回值，参数为TreeNode结点；终止条件：当当前结点为nullptr时，不需要翻转当前结点；每一层逻辑：翻转左右子树，再分别对左右子树调用该递归函数
    reverse(t -> left);
    reverse(t -> right);
    TreeNode * temp = t -> left;
    t -> left = t -> right;
    t -> right = temp;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;
    }
};
```

迭代法：前序、后续、层序遍历均可  
前序：  
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
    TreeNode* invertTree(TreeNode* root) {
        // 前序遍历
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode * t= stk.top();
            stk.pop();
            // 前序遍历，右子树先入栈，可以画一棵树模拟一下前序遍历
            if (t) {
                stk.push(t -> right);
                stk.push(t -> left);
                TreeNode * temp = t -> left;
                t -> left = t -> right;
                t -> right = temp;
            }
            
        }
        return root;
    }
};
```
后序遍历与前序遍历类似。  
层次遍历：  
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
    TreeNode* invertTree(TreeNode* root) {
        // 层序遍历
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            for (int i = 0; i < dq.size(); ++i) {
                TreeNode * t = dq.front();
                dq.pop_front();
                if (t) {
                    dq.push_back(t -> left);
                    dq.push_back(t -> right);
                    TreeNode * temp = t -> left;
                    t -> left = t -> right;
                    t -> right = temp;
                }
            }
        }
        return root;
    }
};
```
