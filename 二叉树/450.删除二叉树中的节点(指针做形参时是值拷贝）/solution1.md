迭代法：  
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
static TreeNode * pre = nullptr;

// 如果能够找到要删除的节点，则返回该节点，pre 记录其父节点
TreeNode * find(TreeNode * root, int key) {
    if (root == nullptr) return nullptr;
    if (root -> val == key) return root;

    pre = root;
    if (root -> val < key) 
        return find(root -> right, key);
    else 
        return find(root -> left, key);
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        pre = nullptr;
        if (root == nullptr) return nullptr;
        TreeNode * target = find(root, key);
        if (target == nullptr) return root;
        // 首先处理特殊情况：根节点本身就是要删除的节点
        if (pre == nullptr) {
            if (root -> left == nullptr && root -> right == nullptr) {
                return nullptr;
            }
            if (root -> left != nullptr && root -> right == nullptr) {
                return root -> left;
            }
            if (root -> left == nullptr && root -> right != nullptr) {
                return root -> right;
            }
            TreeNode * t = root -> right; // 用 root -> right 替代 root
            while (t -> left) 
                t = t -> left;
            t -> left = root -> left;
            return root -> right;
        }
        // 找到了要删除的节点后，思路是这样的：要删除的节点的父节点及其以上部分是不用动的，要动的只有被删除节点的左右子树
        // 如果要删除节点无孩子，那么直接删除
        // 如果要删除节点只有一个孩子，那么直接让父节点指向它（要判断大小，看父节点的左孩子还是右孩子指向它）
        // 如果有两个孩子，把右孩子提上来代替要删除的节点，此时该右孩子的所有孩子节点都是大于要删除节点的左孩子的，所以要删除节点的左孩子可以直接跟到该右孩子节点的最左边孩子节点上（如果有）
        if (target -> left == nullptr && target -> right == nullptr) { // 要删除节点无左右孩子
            if (pre -> val > target -> val) { // target 是其父节点的左孩子
                pre -> left = nullptr;
                return root;
            } else {
                pre -> right = nullptr;
                return root;
            }
        }
        if (target -> left == nullptr && target -> right != nullptr) {
            if (pre -> val > target -> val) {
                pre -> left = target -> right;
                return root;
            } else {
                pre -> right = target -> right;
                return root;
            }
        }
        if (target -> left != nullptr && target -> right == nullptr) {
            if (pre -> val > target -> val) {
                pre -> left = target -> left;
                return root;
            } else {
                pre -> right = target -> left;
                return root;
            }
        }
        // target 两个孩子都在
        TreeNode * t = target -> right; // 用 target -> right 替代 target
        while (t -> left)   
            t = t -> left;
        t -> left = target -> left;
        if (pre -> val > target -> val) {
            pre -> left = target -> right;
            return root;
        } else {
            pre -> right = target -> right;
            return root; // 当前层不为 key，返回当前层节点。在最下面那种混乱的递归逻辑中，这里返回的是 nullptr
        }
    }
};
```
递归：  
递归的思路是：
思路：如果遇到了key，则令该节点等于 nullptr，递归其左右孩子不等于 key 的节点返回，最后返回 nullptr ；如果当前节点不是 key，则返回该节点，让父亲节点指向它
思路：如果当前层遇到了返回的 nullptr，说明这个子树是个 key，则令该分支等于 nullptr；如果遇到了非 nullptr 节点，说明返回的节点不是 key，则指向它
在 669.修建二叉搜索树中,也是利用这种思路来解题。  

注意，之前的递归思路，即
“如果需要删除一个节点v，那么就返回不为空的v的孩子节点的TreeNode\*值，父节点收到不为 Nullptr的指针值后，说明自己的孩子节点被删除，因此自己指向该结点。如果一个叶子节点被删除，就直接删除该节点，让此节点等于nullptr即可。”  
这种思路是逻辑混乱的！
递归程序代码：
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
// 思路：如果遇到了key，则令该节点等于 nullptr，递归其左右孩子不等于 key 的节点返回，最后返回 nullptr ；如果当前节点不是 key，则返回该节点，让父亲节点指向它
 // 思路：如果当前层遇到了返回的 nullptr，说明这个子树是个 key，则令该分支等于 nullptr；如果遇到了非 nullptr 节点，说明返回的节点不是 key，则指向它
TreeNode * deltree(TreeNode * & root, int key) {
    if (root == nullptr) return nullptr;
    if (root -> val == key) {
        // 要删除的节点的几种情况：无孩子，有左、右孩子
        // 无孩子
        if (root -> left == nullptr && root -> right == nullptr) {
            delete root;
            root = nullptr;
            return nullptr; // 左右孩子没有可返回的不等于 key 的节点，自己是 key ，则返回 nullptr
        } else if (root -> left != nullptr && root -> right == nullptr) {
            return deltree(root -> left, key); // root -> left 可能不是 key，至于到底是不是key，递归该层时会判断
        } else if (root -> left == nullptr && root -> right != nullptr) {
            return deltree(root -> right, key);
        } else {
            TreeNode * t = root -> right;
            TreeNode * tmp = root -> right;
            while (tmp -> left) {
                tmp = tmp -> left;
            }

            tmp -> left = root -> left;
            return deltree(t, key);
        }
    }

    // 当前层不为 key，处理完左右子树后，返回当前层节点
    if (root -> val < key) {
        root -> right = deltree(root -> right, key);
    } else {
        root -> left = deltree(root -> left, key);
    }

    return root; // 返回当前层节点
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * t = deltree(root, key);
        return t;
    }
};
```

下面的第一次做的时候，混乱的递归逻辑：
递归：  
递归的思路是：如果需要删除一个节点v，那么就返回不为空的v的孩子节点的TreeNode\*值，父节点收到不为 Nullptr的指针值后，说明自己的孩子节点被删除，因此自己指向该结点。如果一个叶子节点被删除，就直接删除该节点，让此节点等于nullptr即可。
这里需要特别注意，**一个函数的形参是指针，那么传递指针时是值传递**！因此要在一个函数中令主程序中传过来的指针为 nullptr，需要让参数为指针的引用，详见：
[关于指针做函数参数-》指针的值传递和引用传递](https://www.cnblogs.com/San-Francisco/p/17031588.html)  
递归程序代码：

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
// 递归思路：类似701.二搜索树的插入操作的递归法，返回一个要插入的结点，父节点如果接到了孩子返回的不为 nullptr 的结点，就要在这个孩子处构造该结点
// 删除结点的递归思路：如果没有删除就返回 nullptr ，如果递归过程中遇到了本结点是需要被删除的结点，就返回给父结点删除本结点后父结点需要指向的新节点。同样的，本层递归逻辑中，如果父结点接收到了孩子结点返回的不为空的结点，就要指向该不为空的结点
TreeNode * deletetree(TreeNode * &root, int key) {
    if (root == nullptr) return nullptr; // 本条路径上没有需要被删除的结点
    if (root -> val == key) {
        if (!root -> left && !root -> right) { // 直接删除一个结点，用 delete
            delete root;
            root = nullptr; // 注意此处令形参传过来的节点指针值为 nullptr，需要形参 root 为指针的引用形参，而不是指针形参，否则只是令一个实参的拷贝等于 nullptr！
            return nullptr;
        } else if (root -> left && !root -> right) {
            TreeNode * t = root -> left;
            delete root;
            root = nullptr;
            return t;
        } else if (!root -> left && root -> right) {
            TreeNode * t = root -> right;
            delete root;
            root = nullptr;
            return t;
        } else { // 左右孩子都不为空，删除本节点，让本节点的右孩子代替本节点，本节点的左孩子接到本节点右孩子的最左的左孩子节点上
            TreeNode * t = root -> right;
            TreeNode * temp = root -> right;
            while (temp -> left) {
                temp = temp -> left;
            }
            temp -> left = root -> left;
            delete root;
            root = nullptr;
            return t;
        }
    }

    // 当前层递归逻辑
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
    if (root -> val < key) {
        right = deletetree(root -> right, key);
    } else {
        left = deletetree(root -> left, key);
    }

    if (right) 
        root -> right = right;
    if (left)
        root -> left = left;
    return nullptr;

}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * t = deletetree(root, key);
        if (t) return t; // 如果根节点本身就是要找的值，那么 delete(root, key) 会返回一个不为空的指针，该指针是新的头节点
        if (root) 
            return root;
        else // 根节点被删除，即根节点本身就是要找的节点，或者
            return nullptr;
    }
};
```

