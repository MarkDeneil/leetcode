设置哑结点 dummy，这样可以不用单独考虑头结点  
设置 pre, first, second, tmp 结点，first 和 second 结点是需要两两交换的结点，pre 和 tmp 分别是前面的结点和后面的结点  
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode * dummy = new ListNode(-1, head);
        ListNode * pre = dummy;
        ListNode * first = dummy -> next;
        ListNode * second = first -> next;
        if (second == nullptr) return first;
        ListNode * newhead = second;
        while (first && second)
        {
            ListNode * tmp = second -> next;
            pre -> next = second;
            second -> next = first;
            first -> next = tmp;

            pre = first;
            first = first -> next;

            if (first) second = first -> next;
        }
        return newhead;
        
    }
};
```
