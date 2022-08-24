双指针法，思想1：  
假设 p 和 q 有相交结点的情况，让 p 和 q 同时走，p -> next == nullptr 时，让其指向 headB，同时 q -> next == nullptr 时，让其指向 headA；  
这样最终 p == q 时退出循环，此时 p, q 指向相交结点.  
假设 p 和 q 没有相交结点，让 p 和 q 同时走，p -> next == nullptr 时，让其指向 headB，同时 q -> next == nullptr 时，让其指向 headA；  
再继续走，这样最终 p 和 q 会**同时**指向 nullptr，因此 循环终止条件中还需要有**p 和 q 不同时为 nullptr**  
最后注意，需要在循环内判定 (p -> next == nullptr && q -> next == nullptr), 这种情况就是第二轮走时没有相交结点的情况，应该退出循环，否则会陷入死循环  
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
        ListNode * dummy = new ListNode(-1, headA);
        ListNode * dummy1 = new ListNode(-1, headB);
        ListNode * p = dummy;
        ListNode * q = dummy1;
        while ((p != q) && (p || q))
        {
            if (p -> next == nullptr && q -> next == nullptr) return nullptr;
            p -> next == nullptr ? p = dummy1 : p = p -> next;
            q -> next == nullptr ? q = dummy : q = q -> next;
        }
        return p;
    }
};
```
（推荐）双指针法，思想2：  
判定结点是否相交、找倒数第 N 个结点之类（19题），都可以利用双指针法，让一个指针先到特定位置，再同时行进指针  
这里先遍历链表，找出比较长的一个，让其指针先行进两个链表差的长度，再同时行进，当 p == q 时，即为相交结点  
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
        ListNode * dummy = new ListNode(-1, headA);
        ListNode * dummy1 = new ListNode(-1, headB);
        ListNode * p = dummy;
        ListNode * q = dummy1;
        int sizeA = 0;
        int sizeB = 0;
        while (p -> next || q -> next)
        {
            if (p -> next)
            {
                ++sizeA;
                p = p -> next;
            }
            if (q -> next)
            {
                ++sizeB;
                q = q -> next;
            }
        }
        p = dummy;
        q = dummy1;
        if (sizeA >= sizeB)
        {
            for (int i = 0; i < sizeA - sizeB; ++i)
            {
                p = p -> next;
            }
        }
        else
        {
            for (int i = 0; i < sizeB - sizeA; ++i)
            {
                q = q -> next;
            }
        }
        while (p != q)
        {
            if (!p && !q) return nullptr;
            p = p -> next;
            q = q -> next;
        }
        return p;
    }
};
```


