设计链表时，要注意链表刚开始的判空操作  
此外，在使用默认构造函数 `MyLinkedList * p = new MyLinkedList();` 生成链表时，会产生一个 val = 0，next = nullptr 的结点，作为哑结点（虚拟头结点），之后的操作要注意都是在这个结点之后进行的，即之后的操作中生成的链表是不包含这个结点的  
```cpp
class MyLinkedList {
public:
    MyLinkedList(int v = 0, MyLinkedList * n = nullptr):val(v), next(n) {

    }
    
    int get(int index) {
        if (index < 0) return -1;
        MyLinkedList * p = this -> next; // 链表开头有一个值为 0 的结点，是在最初默认初始化时生成的
        if (p == nullptr) return -1;
        for (int i = 0; i < index; ++i)
        {
            p = p -> next;
            if (p == nullptr) return -1;
        }
        return p -> val;
    }
    
    void addAtHead(int val) {
        // this 始终指向链表开头 val 为 0 的那个结点
        MyLinkedList * node = new MyLinkedList(val);
        MyLinkedList * p = this -> next;
        node -> next = this -> next;
        this -> next = node;
    }
    
    void addAtTail(int val) {
        MyLinkedList * node = new MyLinkedList(val);
        MyLinkedList * p = this -> next;
        if (p == nullptr)
        {
            this -> next = node;
        }
        else
        {
            while (p -> next != nullptr)
            {
                p = p -> next;
            }
            p -> next = node;
            
        }    
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList * p = this -> next;
        if (p == nullptr)
        {
            if (index <= 0)
            {
                MyLinkedList * node = new MyLinkedList(val);
                this -> next = node;
            }
        }
        else
        {
            if (index < 0)
            {
                MyLinkedList * node = new MyLinkedList(val);
                node -> next = this -> next;
                this -> next = node;
            }
            else
            {
                MyLinkedList * pre = this;
                for (int i = 0; i < index; ++i)
                {
                    if (p != nullptr) // 接下来需要对指针 p 进行 p = p -> next; 操作，因此需要对 p 进行判空，否则会可能出现空指针引用错误
                    {
                        pre = p;
                        p = p -> next;
                    }
                }
                if (pre != nullptr)
                {
                    MyLinkedList * node = new MyLinkedList(val);
                    if (p == nullptr) // 插入末尾
                    {
                        pre -> next = node;
                    }
                    else
                    {
                        node -> next = p;
                        pre -> next = node;
                    }
                }
            }
        }
    }
    
    void deleteAtIndex(int index) {
        MyLinkedList * p = this -> next;
        if (p == nullptr || index < 0) return;
        MyLinkedList * pre = this;
        for (int i = 0; i < index; ++i)
        {
            if (p != nullptr)
            {
                pre = p;
                p = p -> next;
            }
        }
        if (p != nullptr)
        {
            pre -> next = p -> next;
            delete p;
        }
    }
private:
    int val;
    MyLinkedList * next;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
 ```
