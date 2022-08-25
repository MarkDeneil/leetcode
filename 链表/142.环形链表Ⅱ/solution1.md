双指针法  
这类链表题目一般都是使用双指针法解决的，例如**寻找距离尾部第K个节点、寻找环入口、寻找公共尾部入口**等。  
设置快慢指针，两个要点：  
1. 当快指针和慢指针可以相遇时，则一定有环  
2. 若有环，从快慢指针相遇的结点开始到环的入口距离与从链表头到环的入口距离相同  
设置哑结点的版本：  
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode * dummy = new ListNode(0, head);
        ListNode * slow = dummy, * fast = dummy;
        ListNode * index1 = dummy;
        ListNode * index2;
        while (slow != nullptr)
        {
            slow = slow -> next;
            if (fast) fast = fast -> next;
            if (fast) fast = fast -> next;
            if ((slow && fast) && (slow == fast))
            {
                index2 = slow;
                while (index1 != index2)
                {
                    if (index1) index1 = index1 -> next;
                    if (index2) index2 = index2 -> next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
```
不设置哑结点：  
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode * slow = head, * fast = head;
        ListNode * index1 = head, * index2;
        while (slow != nullptr)
        {
            slow = slow -> next;
            if (fast) fast = fast -> next;
            if (fast) fast = fast -> next;
            if ((slow && fast) && (slow == fast)) // 有环
            {
                index2 = slow;
                while (index1 != index2)
                {
                    index1 = index1 -> next;
                    index2 = index2 -> next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
```
