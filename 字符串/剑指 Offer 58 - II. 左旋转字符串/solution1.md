不适用辅助空间  
思想：  
1. 反转区间为前n的子串  
2. 反转区间为n到末尾的子串  
3. 反转整个字符串  
```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
```
