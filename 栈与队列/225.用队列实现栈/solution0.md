```cpp
class MyStack {
private:
    deque<int> d1;
    deque<int> d2;
public:
    MyStack() {

    }
    
    void push(int x) {
        d1.push_back(x);
    }
    
    int pop() {
        // 只要进行弹出操作，就要清空 d1
        while (!d1.empty()){
            int temp = d1.front();
            d1.pop_front();
            d2.push_back(temp);
        }
        int x = d2.back();
        d2.pop_back();
        return x;
    }
    
    int top() {
        int x = pop();
        push(x);
        return x;
    }
    
    bool empty() {
        return d1.empty() && d2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 ```
