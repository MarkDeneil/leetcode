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
  
双指针法移除空格：
- 快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组  
- 慢指针：指向更新 新数组下标的位置  
在本题中，如果快指针指向的不是连续的第二个空格，则就将快指针指向的字符赋给慢指针  
对快慢指针的新理解：  
其实就是利用快指针来找不含有目标元素的数据，在赋值给慢指针，这个过程相当于**用慢指针在原来的数组中一点点构建一个新的数组**。在本题中，如果快指针指向了连续的第二个空格，那么这个空格理应不出现在新的数组中，所以此时只需要1）快指针不赋值给慢指针（因为此时快指针指向的元素不应该出现的新数组中） 2）快指针跳过该空格 即可。  
```cpp
class Solution {
public:
    string reverseWords(string s) {
        // 使用双指针法删除连续两个存在的空格中的第二个，然后删除首位空格，最后用 resize() 函数调整字符串大小
        int size = s.size();
        int count = 0; // count 记录被删除的空格数，用作最后 resize() 用
        if (s.size() == 1) return s;
        int fast = 1, last = 1; // 不从首元素开始
        for (; last < s.size(); ++last)
        {
            if (s[last] != ' ' || s[last - 1] != ' ')
            {
                s[fast] = s[last];
                ++fast;
            }
            else
                ++count;
        }
        s.resize(size - count);
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
