利用栈  
```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        if (s.size() == 1) return s;
        // 利用栈
        stack<char> stk;
        for (auto x : s){
            if (!stk.empty()){
                if (x == stk.top()){
                    stk.pop();
                } else {
                    stk.push(x);
                }
            } else {
                stk.push(x);
            }
        }
        string res;
        while (!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        // 反转 res
        int first = 0, second = res.size() - 1;
        while (second > first){
            char t = res[second];
            res[second] = res[first];
            res[first] = t;
            --second;
            ++first;
        }
        return res;

    }
};
```
