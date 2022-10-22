逆波兰表达式求值过程：遍历该逆波兰表达式，遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。  
![150 逆波兰表达式求值-1](https://user-images.githubusercontent.com/83362131/197346192-180a4507-9f8f-4e76-a456-99db81b584ec.gif)
要注意的是，int 有可能表示不了某些结果，因此用 long long 
```cpp
class Solution {
public:
    long long evalRPN(vector<string>& tokens) {
        stack<long long> stk1;
        for (auto x : tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                long long num1 = stk1.top();
                stk1.pop();
                long long num2 = stk1.top();
                stk1.pop();
                if (x == "+") {
                    stk1.push(num1 + num2);
                } else if (x == "-") {
                    stk1.push(num2 - num1); // 注意减的顺序不要弄错
                } else if (x == "*") {
                    stk1.push(num1 * num2);
                } else {
                    stk1.push(num2 / num1);
                }
            }
            else {
                stk1.push(stoi(x));
            }
        }
        long long res = stk1.top();
        return res;
    }
};
```
