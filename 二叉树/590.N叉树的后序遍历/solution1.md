参考 二叉树的后序遍历 过程：  
![393A631D843B09930F368042335AD548](https://user-images.githubusercontent.com/83362131/203791513-ca17f10e-043f-47d0-921a-7703d7251048.png)  
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node *> stk;
        if (root == nullptr) return vector<int>();
        vector<int> res;
        stk.push(root);
        while (!stk.empty()) {
            Node * t = stk.top(); // 先不弹出，前序遍历要求中左右，那么右节点先入栈，紧接着左结点
            stack<Node *> tempstk; // 调整结点入栈顺序的辅助栈
            for (auto x : t->children) {
                if (x)tempstk.push(x);
            }
            while (!tempstk.empty()) {
                Node * s = tempstk.top();
                tempstk.pop();
                stk.push(s); // 相当于右结点先入 stk 栈
            }
            t->children.clear();
            t = stk.top();
            if (t -> children.empty()) {
                res.push_back(t -> val);
                stk.pop();
            }
        } 
        return  res;
    }
};
```
