没有想出遍历一次的方法；  
先算出大小，再删除  
设置哑结点；注意如果删除的结点是头结点，则需要单独讨论  
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode * dummy = new ListNode(-1, head);
        ListNode * p = head;
        int size = 1;
        while (p -> next)
        {
            ++size;
            p = p -> next;
        }
        if (n == size)
        {
            ListNode * tmp = head;
            head = head -> next;
            delete tmp;
            return head;
        }
        p = dummy;
        for (int i = 0; i < size - n; ++i)
        {
            p = p -> next;
        }
        ListNode * tmp = p -> next;
        p -> next = tmp -> next;
        delete tmp;
        delete dummy;
        return head;
    }
};
```
