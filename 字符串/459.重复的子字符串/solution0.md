暴力解法：  
从 i == 1 到 i == s.size() 作为子字符串的长度测试可能的子字符串。  
```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        if (size == 1) return false;
        int i = 1; // 子串可能的长度
        for (; i < size; ++i)
        {
            if (size % i == 0)
            {
                int tmp = size / i;
                string subs(s.begin(), s.begin() + i);
                string res;
                for (int j = 0; j < tmp; ++j)
                {
                    res += subs;
                }
                if (s == res) return true;
            }
        }
        return false;
    }
};
```
