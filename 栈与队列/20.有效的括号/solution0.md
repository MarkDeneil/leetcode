```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        for (auto x : s){
            if (x == '(' || x == '[' || x == '{') {
                stk.push(x);
            } else {
                if (x == ')') {
                    if (!stk.empty() && stk.top() == '(') { // 判定栈是否为空这一点，容易忘记
                        stk.pop();
                    } else 
                        return false;
                } else if (x == ']') {
                    if (!stk.empty() && stk.top() == '[') {
                        stk.pop();
                    } else 
                        return false;
                } else {
                    if (!stk.empty() && stk.top() == '{') {
                        stk.pop();
                    } else 
                        return false;
                }
            }
        }
        return stk.empty();
    }
};
```
