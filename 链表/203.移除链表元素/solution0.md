前两次提交未通过的测试用例：  
[],1  
输出：[]  
[7,7,7,7],7  
输出：[]  
原因：没有在两个 while 循环中判断 `head != nullptr` 导致  
都只判断了 `p -> next != nullptr`    
因此：不仅要对链表下一个指针判空，还要对当前指针判空  
```cpp
/*
struct ListNode{
  int val;
  ListNode * next;
  ListNode():val(0), next(nullptr) {};
  ListNode(int v):val(v), next(nullptr) {}
  ListNode(int v, ListNode * n):val(v), next(n) {}
};
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head -> val == val)
        {
            ListNode *p = head;
            head = head -> next;
            delete p;
        }
        ListNode *p = head;
        while (p != nullptr && p -> next != nullptr)
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
