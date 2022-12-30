有两种解法，第一种是将树遍历一遍，存入 map<int, int> 中，计算树的每一个元素的出现次数。  
但是该种解法没有用到二叉搜索树：中序遍历是递增序列 的性质  
第二种解法利用了这种性质，从一个有序数组中寻找出现元素最多的树，只需不断比较数组中相邻的前后两个元素出现的个数即可。  
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
void findbin(TreeNode * t, map<int, int> & m) {
    if (t == nullptr) return ;
    findbin(t -> left, m);

    int val = t -> val;
    pair<map<const int, int>::iterator, bool> p = m.insert(make_pair(val, 1));
    if (p.second == false) {
        ++((p.first) -> second);
    }

    findbin(t -> right, m);
}


class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // 中序遍历，把值写入 map 中
        if (root == nullptr) return vector<int>();
        vector<int> res;
        map<int, int> m;
        findbin(root, m);

        int maxcount = -1;
        for (auto x : m) {
            if (x.second >= maxcount) maxcount = x.second;
        }

        for (auto x : m) {
            if (x.second == maxcount) 
                res.push_back(x.first);
        }
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

// 参数和返回值
TreeNode * pre = nullptr;
int maxcount = 0;
int curcount = 0;
vector<int> vec;

void findbin(TreeNode * cur) {
    if (cur == nullptr) return ;
    findbin(cur -> left);

    if (pre == nullptr) {
        curcount = 1;
    } else {
        if (pre -> val == cur -> val) {
            ++curcount;
        } else {
            curcount = 1;
        }
    }

    pre = cur;
    if (curcount == maxcount) {
        vec.push_back(cur -> val);
    } 
    if (curcount > maxcount) {
        maxcount = curcount;
        vec.clear();
        vec.push_back(cur -> val);
    }

    findbin(cur -> right);

    return;

}

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // 利用二叉搜索树中序遍历是有序递增数组的特点，在有序数组中找出现频率最高的元素，每次只需比较前后两个元素
        if (root == nullptr) return vector<int>();
        curcount = 0;
        maxcount = 0;
        pre = nullptr;
        
        findbin(root);
        return vec;
    }
};
```
