移动匹配：  
若 s 是一个由子串构成的字符串，则 t = s + s 去掉头一个字符和尾字符后，中间一定还包含一个 s。  
```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != string::npos) return true;
        return false;
    }
};
```
