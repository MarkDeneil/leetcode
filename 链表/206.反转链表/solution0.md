迭代法：  
首先想到的是头插法  
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
    ListNode* reverseList(ListNode* head) {
        // 迭代法
        if (head == nullptr) return nullptr;
        ListNode * dummy = new ListNode(-5001, head); // 哑结点
        ListNode * p = dummy -> next;
        // 建立新的链表头结点，遍历原链表，每遍历一个结点就头插到新链表中
        ListNode * newdummy = new ListNode(-5001, nullptr);
        while (p != nullptr)
        {
            ListNode * node = new ListNode(p -> val);
            node -> next = newdummy -> next;
            newdummy -> next = node;
            p = p -> next;
        }
        return newdummy -> next;
    }
};
```
实际上还有双指针法，见 
