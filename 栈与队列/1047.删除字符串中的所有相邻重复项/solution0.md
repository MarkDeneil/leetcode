BF  
需要掌握 string 的 erase() 以及注意 erase 操作后迭代器是否失效的问题  
```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        // BF
        if (s.size() == 1) return s;
        int tag = 0;
        string::iterator it;
        for (it = s.begin(); it != s.end() - 1 && it != s.end();){ // 添加上 it != s.end() 是应对 s=“aa” 这种情况。
            if (*it == *(it + 1)){
                if (it != s.begin()){
                    string::iterator temp = it - 1;
                    if (it != s.end() - 1)
                        s.erase(it + 1); // 注意，先 erase it +1 ,再 erase it
                    s.erase(it);
                    it = temp;
                } else {
                    s.erase(it);
                    it = s.begin();
                    s.erase(it);
                    it = s.begin();
                }
            } else {
                if (s.size() <= 1) return s;
                ++it;
            }
        }
        return s;
    }
};
```
