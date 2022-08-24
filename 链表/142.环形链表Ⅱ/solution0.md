使用一个数组将指向已经遍历过的链表中的结点的指针都存储起来，每有一个新的结点就将指向该节点的指针与存储起来的所有指针相比较  
时间复杂度：  
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <vector>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode * dummy = new ListNode(0, head);
        vector<ListNode *> vec;
        ListNode * p = dummy;
        vector<ListNode *>::iterator it;
        while (p -> next != nullptr)
        {
            p = p -> next;
            it = vec.begin();
            while (it != vec.end())
            {
                if (p == *it) return p;
                ++it;
            }
            vec.push_back(p);
        }
        return nullptr;
    }
};
```
