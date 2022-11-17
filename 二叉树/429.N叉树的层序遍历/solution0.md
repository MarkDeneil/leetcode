主要难点在于看清二叉树与N叉树结构的不同  
N叉树不再是 left 和 right 两个孩子结点，而是`vector<Node*> children;`所有的孩子结点的指针都存在一个 vector 中  
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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        deque<Node *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> tempres; // 记录本层的值
            for (int i = 0; i < size; ++i) {
                Node * t = dq.front();
                dq.pop_front();

                for (int j = 0; j < (t -> children).size(); ++j) {
                    if ((t -> children)[j]) dq.push_back((t ->children)[j]);
                }

                // for (auto x : t -> children) {
                //     if (x) dq.push_back(x);
                // }
                
                tempres.push_back(t -> val);
            }
            res.push_back(tempres);
        }
        return res;
    }
};
```
