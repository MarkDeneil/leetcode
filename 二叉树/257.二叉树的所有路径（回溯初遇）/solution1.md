![D7E1952D78C70AEBA2A6EB72FA664411](https://user-images.githubusercontent.com/83362131/205103114-3d493eca-eaa8-47db-a479-e0034889081d.png)
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

//因为求根节点到叶子节点的路径，从上往下求，用前序遍历，递归+回溯
// 参数：结点 t，存放结点值的 vec 以及存放结果的 res，注意都是引用
void reversal(TreeNode * t, vector<int> & vec, vector<string> & res) {
    // 终止条件应该到叶子结点就终止并构造string，不应该是判断空结点，因此需要在单层逻辑中不让空结点进入递归。
    // 先将本结点的值加入到 vec，如果是叶子节点，则可以构造 string 并放入 res 中
    vec.push_back(t -> val);
    if (t -> left == nullptr && t -> right == nullptr) {
        string s;
        int size = vec.size();
        for (int i = 0; i < size - 1; ++i) {
            s += to_string(vec[i]);
            s += "->";
        }
        s += to_string(vec[size - 1]);
        res.push_back(s);
        return ;
    }
    if (t -> left) { // 不让空结点进入递归
        reversal(t -> left, vec, res);
        vec.pop_back(); // 注意，回溯和递归在一起，不能一个在花括号里面，一个在花括号外面
    }
    if (t -> right) {
        reversal(t -> right, vec, res);
        vec.pop_back();
    }
    return ;
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return vector<string>();
        vector<int> vec;
        vector<string> res;
        reversal(root, vec, res);
        return res;
    }
};
```

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

//因为求根节点到叶子节点的路径，从上往下求，用前序遍历，递归+回溯
// 参数：结点 t，构造过程中的字符串 s 以及存放结果的 res 引用
void reversal(TreeNode * t, string s, vector<string> & res) {
    if (t -> left == nullptr && t -> right == nullptr) { // 终止条件：仍然是叶子结点
        s += to_string(t -> val);
        res.push_back(s);
        return ; // 注意，不要忘了 return; 语句
    }
    // 接下来是本层逻辑
    // 非叶子结点
    s += to_string(t -> val);
    s += "->";
    if (t -> left) {
        reversal(t -> left, s, res);
        // 因为 s 不是引用，所以即使经历了上面的递归程序，s 仍然没有发生改变，传递给下一个递归的仍然是该 s，所以不用回溯
    }
    if (t -> right) {
        reversal(t -> right, s, res);
    }
    return ;
    
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return vector<string>();
        vector<string> res;
        string s;
        reversal(root, s, res);
        return res;
    }
};
```

使用迭代，模拟递归，需要两个栈  
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
    vector<string> binaryTreePaths(TreeNode* root) {
        // 迭代，使用工具（栈等）来模拟递归
        // 模拟前序遍历
        stack<TreeNode *> stk;
        stack<string> stkstring;
        vector<string> res;
        if (root == nullptr) return vector<string>();
        stk.push(root);
        stkstring.push(to_string(root->val));
        while (!stk.empty()) {
            TreeNode * t = stk.top();
            stk.pop();
            string s = stkstring.top();
            stkstring.pop();
            if (t -> left == nullptr && t -> right == nullptr) {
                res.push_back(s);
            }
            
            if (t -> left) {
                stk.push(t -> left);
                stkstring.push(s + "->" + to_string(t -> left -> val));
            }
            if (t -> right) {
                stk.push(t -> right);
                stkstring.push(s + "->" + to_string(t -> right -> val));
            }
        }
        return res;
    }
};
```
