迭代法：  
除了头插法外，还有双指针法，通过**改变结点指针的指向**来反转链表，更快速  
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
        // 双指针法反转列表
        if (head == nullptr) return nullptr;
        ListNode * pre = head, * p = head -> next;
        head -> next = nullptr; // 反转后，head 就成为最后一个结点
        while (p != nullptr)
        {
            ListNode * tmp = p -> next;
            p -> next = pre;
            pre = p;
            p = tmp;
        }
        return pre;
    }
};
```
