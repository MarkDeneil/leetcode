pop 函数比 solution0 简单  
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
        // 输出栈如果为空，就把进栈数据全部导入进来（注意是全部导入），再从出栈弹出数据，如果输出栈不为空，则直接从出栈弹出数据就可以了。
        if (!s2.empty()){
            int x = s2.top();
            s2.pop();
            return x;
        } else {
            while (!s1.empty()){
                int temp = s1.top();
                s2.push(temp);
                s1.pop();
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    int peek() {
        if (!s2.empty()){
            int x = s2.top();
            return x;
        } else {
            while (!s1.empty()){
                int temp = s1.top();
                s2.push(temp);
                s1.pop();
            }
            int x = s2.top();
            return x;
        }
    }
    
    bool empty() {
        // 如果进栈和出栈都为空的话，说明模拟的队列为空了。
        return s1.empty() && s2.empty();
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
