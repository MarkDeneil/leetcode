双指针的经典应用，如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，直到fast指向链表末尾。删掉slow所指向的节点就可以了。
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
        ListNode * f = dummy, * l = dummy;
        for (int i = 0; i < n; ++i)
            f = f -> next;
        while (f -> next)
        {
            l = l -> next;
            f = f -> next;
        }
        if (l == dummy) // 需要删除第一个结点
        {
            ListNode * tmp = head;
            head = head -> next;
            delete dummy;
            delete tmp;
            return head;
        }
        ListNode * tmp = l -> next;
        l -> next = tmp -> next;
        delete tmp;
        delete dummy;
        return head;
    }
};
```
