超出时间限制  
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

// 参数和返回值：将中序和后序数组一直传下去，并且添加一个数组 vec，当 vec 中的大小大于等于 1 时，继续根据中后续数组分，分成一个跟节点
// 和两个小数组，继续递归
// 返回该次递归找到的根节点
TreeNode * construct(vector<int>& inorder, vector<int>& postorder, vector<int> vec) {
    // 终止条件：当传入该递归函数的 vec 的 size 小于等于1 时，直接返回该节点作为叶子节点（也可以看作根节点，没有孩子的本层的根节点
    if (vec.size() == 0) return nullptr;
    if (vec.size() == 1) {
        TreeNode * t = new TreeNode(vec[0], nullptr, nullptr);
        return t;
    }
    // 当传入的数组大小大于 1 时，分割该数组，继续递归
    vector<int> a, b;
    // 后序数组中的最后一个节点是该层找到的根节点
    int rootval = -1;
    // 反向便利 postorder，第一个出现在 vec 中的数即为该层找到的跟节点
    int tag = 0;
    // 找到根节点后该数置为 1
    vector<int>::reverse_iterator it, it1;
    for (it = postorder.rbegin(), it1 = postorder.rend(); it != it1; ++it) {
        for (auto x : vec) {
            if (*it == x) {
                rootval = x;
                tag = 1;
                break;
            }
        }
        if (tag == 1) {
            break;
        }
    }
    vector<int> left;
    vector<int> right;
    for (auto x : inorder) {
        if (x == rootval) break;
        for (auto y : vec) {
            if (x == y) 
                left.push_back(x);
        }
    }

    for (it = inorder.rbegin(), it1 = postorder.rend(); it != it1; ++it) {
        if (*it == rootval) break;
        for (auto y : vec) {
            if (*it == y) {
                right.push_back(*it);
            }
        }
    }
    TreeNode * curroot = new TreeNode(rootval, construct(inorder, postorder, left), construct(inorder, postorder, right));
    return curroot;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int> vec(postorder);
        return construct(inorder, postorder, vec);
    }
};
```
