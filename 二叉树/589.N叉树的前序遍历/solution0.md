把二叉树的前序遍历中，先入栈右孩子、再入栈左孩子换成了先入栈vector<Node*>中最后的结点，再入栈vector<Node*>中的第一个结点；为此需要一个辅助栈；  
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
    vector<int> preorder(Node* root) {
        stack<Node *> stk;
        if (root == nullptr) return vector<int>();
        vector<int> res;
        stk.push(root);
        while (!stk.empty()) {
            Node * t = stk.top(); // 先不弹出，前序遍历要求中左右，那么右节点先入栈，紧接着左结点
            res.push_back(t -> val);
            stk.pop();
            stack<Node *> tempstk; // 调整结点入栈顺序的辅助栈
            for (auto x : t->children) {
                if (x)tempstk.push(x);
            }
            while (!tempstk.empty()) {
                Node * s = tempstk.top();
                tempstk.pop();
                stk.push(s); // 相当于右结点先入 stk 栈
            }
        } 
        return  res;
    }
};
```
