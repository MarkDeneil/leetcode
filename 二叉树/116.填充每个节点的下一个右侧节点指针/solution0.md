```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 层序遍历，在每一层遍历时让当前结点的 next 指针指向下一个结点；最后一个结点时指向空，利用每一层的 size 大小来判断是否为最后一个结点
        if (root == nullptr) return root;
        deque<Node *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            for (int i = 0; i < size - 1; ++i) {
                Node * t = dq.front();
                dq.pop_front();

                // 不能在循环中写 i < size; 来判断，并按照下面的方式处理最后一个结点。因为每一层结束后，下一层的结点已经被加入到 dq 中了，所以除非当前层是最后一层，否则 dq 不可能为空
                // if (!dq.empty())
                //     t -> next = dq.front(); // 如果 dq 为空，说明此时 t 已经是该层的最后一个结点指针，则此结点的 next 指向 nullptr
                // else
                //     t -> next = nullptr;
                t -> next = dq.front();
                if (t -> left) dq.push_back(t -> left);
                if (t -> right) dq.push_back(t -> right);
            }
            // 处理每层的最后结点
            Node * t = dq.front();
            dq.pop_front();
            t -> next = nullptr;
            if (t -> left) dq.push_back(t -> left);
            if (t -> right) dq.push_back(t -> right);
        }
        
        return root;
    }
};
```
