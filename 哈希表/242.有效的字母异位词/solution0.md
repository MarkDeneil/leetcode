使用排序的方法：  
t 是 sss 的异位词等价于「两个字符串排序后相等」  
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 排序 
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

使用关联容器 multiset,但是使用 multiset 效果不好，因为时间慢
```
class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> s1;
        multiset<char> s2;
        for (auto x : s)
            s1.insert(x);
        for (auto x : t)
            s2.insert(x);
        if (s1 == s2) return true;
        return false;
    }
};
```
