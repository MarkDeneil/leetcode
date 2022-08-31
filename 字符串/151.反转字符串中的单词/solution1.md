如果不使用 istringstream,则解体思路如下：  
1. 移除多余空格  
2. 将整个字符串反转  
3. 将每个单词反转  
```cpp
class Solution {
public:
    string reverseWords(string s) {
        // 删除连着的两个空格
        for (int i = s.size() - 1; i > 0; --i)
        {
            if (s[i] == s[i - 1] && s[i] == ' ')
            {
                s.erase(s.begin() + i);
            }
        }
        // 删除最后一个空格
        if (s.size() > 0 && s[s.size() - 1] == ' ')
        {
            s.erase(s.begin() + s.size() - 1);
        }
        // 删除最开始的空格
        if (s.size() > 0 && s[0] == ' ')
        {
            s.erase(s.begin());
        }
        reverse(s.begin(), s.end());
        string::iterator first, second;
        first = second = s.begin();
        while (true)
        {
            if (*second == ' ')
            {
                reverse(first, second); // 迭代器second 正好指向单词的后一个位置
                ++second;
                first = second;
            }
            else 
            {
                ++second;
            }
            if (second == s.end()) // 注意，最后一个单词后面是没有空格的，要特殊处理，因此也不能把 while (second != s.end()) 作为循环结束的条件，否则会漏掉最后一个单词的处理
            {
                reverse(first, second);
                break;
            }
        }
        return s;
        
    }
};
```
上述代码中，删除空格是 O(n^2) 的复杂度，因为 erase() 本身就是 O(n) 的复杂度；可以使用双指针法移除空格（参考 p27)，然后使用 **resize()** 重新设置字符串的大小；  
