```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string::iterator it;
        it = s.begin();
        string temp;
        for (int i = 0; i < n; ++i)
        {
            temp += *it;
            it = s.erase(it);
        }
        return s + temp;
    }
};
```
