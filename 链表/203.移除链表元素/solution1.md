删除链表的某个节点需要从其前一个结点入手，但是头结点没有前一个结点，因此删除链表结点有两种做法：  
1. 不设置哑结点，单独处理头结点  
2. 设置哑结点指向头结点，并可以将头结点与其他结点一同处理  
```cpp
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 处理头节点的删除
        while (head != nullptr && head -> val == val)
        {
            ListNode *p = head;
            head = head -> next;
            delete p;
        }
        // 处理其余节点的删除
        ListNode *p = head;
        if (p == nullptr) return nullptr;
        while (p -> next != nullptr)
        {
            ListNode * pre = p;
            p = p -> next;
            if (p -> val == val)
            {
                pre -> next = p -> next;
                delete p;
                p = pre;
            }
        }
        return head;
    }
};
```
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummynode = new ListNode(-1, head); // 设置哑节点，这样不用单独处理头节点的删除情况
        ListNode * p = dummynode;
        while (p -> next != nullptr)
        {
            ListNode * pre = p;
            p = p -> next;
            if (p -> val == val)
            {
                pre -> next = p -> next;
                delete p;
                p = pre;
            }
        }
        return dummynode -> next;

    }
};
```
