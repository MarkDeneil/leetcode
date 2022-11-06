递归法：  
1. 确定递归函数的参数和返回值： 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。  
2. 确定终止条件： 写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。  
3. 确定单层递归的逻辑： 确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。  
以 144.前序遍历的递归写法为例：
确定递归函数的参数和返回值：因为要打印出前序遍历节点的数值，所以参数里需要传入 vector res 存放结果，除了这一点就不需要在处理什么数据了也不需要有返回值，所以递归函数返回类型就是void，代码如下：  
`void traversal(TreeNode* cur, vector<int>& res);`  
确定终止条件：在递归的过程中，如何算是递归结束了呢，当然是当前遍历的节点是空了，那么本层递归就要要结束了，所以如果当前遍历的这个节点是空，就直接return，代码如下：  
`if (cur == NULL) return;`  
确定单层递归的逻辑：前序遍历是中左右的循序，所以在单层递归的逻辑，是要先取中节点的数值，代码如下：  
```cpp
vec.push_back(cur->val);    // 中
traversal(cur->left, vec);  // 左
traversal(cur->right, vec); // 右
```
最终代码  
```cpp
void priiter(TreeNode * t, vector<int> & res) {
    if (t == nullptr) return ;
    res.push_back(t->val);
    priiter(t->left, res);
    priiter(t->right, res);
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        priiter(root, res);
        return res;
    }
};
```
