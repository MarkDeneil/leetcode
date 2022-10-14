把 pop 函数做复杂了，具体见 solution1  
```cpp
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        // 先将 s1 中的元素放进 s2 中，再弹出 s2 的顶元素，再将 s2 中的元素放入 s1 中
        while (!s1.empty()){
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        while (!s2.empty()){
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return res;
    }
    
    int peek() {
        while (!s1.empty()){
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        int res = s2.top();
        while (!s2.empty()){
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return res;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

```
