没看懂题目意思，写出来一种找出两个链表中相交结点的程序：  
例如，输入  
listA = [4,1,8,4,5], listB = [5,0,1,8,4,5]  
则在结点 1 处相交  
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        // ListNode * dummy1 = new ListNode(-1, headA);
        // ListNode * dummy2 = new ListNode(-1, headB);
        // ListNode * p = dummy1;
        // ListNode * q = dummy2;
        ListNode * p = headA;
        ListNode * q = headB;
        for (; p != nullptr; p = p -> next)
            for (q = headB; q != nullptr; q = q -> next)
                {
                    if (p -> val == q -> val)
                    {
                        ListNode * tmpp = p;
                        ListNode * tmpq = q;
                        while (tmpp -> val == tmpq -> val)
                        {
                            tmpp = tmpp -> next;
                            tmpq = tmpq -> next;
                            if (tmpp == nullptr && tmpq == nullptr) return p;
                        }
                        continue;
                    }
                }
        return nullptr;
    }
};
```
