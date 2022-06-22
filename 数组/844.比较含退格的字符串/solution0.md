```cpp
class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t) ? true : false;
    }
    string build(string &s)
    {
        int size = s.size();
        int fast = size - 1;
        int slow = 0;
        char temp[201];
        int count = 0;
        while (fast >= 0)
        {
            if (s[fast] == '#')
            {
                --fast;
                ++count;
            }
            else
            {
                if (count > 0)
                {
                    --count;
                    --fast;
                }
                else
                {
                    temp[slow] = s[fast];
                    --fast;
                    ++slow;
                }
            }
        }
        string res = temp;
        return res;
    }
};
```

```cpp
class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t) ? true : false;
    }
            string build(string s)
    {
        char res[200];
        int size = s.size();
        int top = 0;
        for (int i = 0; i < size; i++)
        {
            if (s[i] != '#')
            {
                res[top] = s[i];
                ++top;
            }
            else
            {
                if (top > 0) --top;
            }
        }
        if (top <= 0)
        {
            string q;
            return q;
        }
        else 
        {
            char temp[200];
            for (int i = 0; i < top; i++)
            {
                temp[i] = res[i];
            }
            string q = temp;
            return q;
        }

    }
};
```
尝试双指针法，失败
```cpp
class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        int sizes = s.size();
        int sizet = t.size();
        int count1 = 0; // 记录 s 中的 # 的个数
        int count2 = 0;
        int p1 = sizes - 1;
        int p2 = sizet - 1;
        while (p1 != -1 && p2 != -1)
        {
            if (s[p1] != '#' && t[p2] != '#')
            {
                if (s[p1] != t[p2]) return false;
                --p1;
                --p2;
            }
            else 
            {
                if (s[p1] == '#') 
                {
                    --p1;
                    ++count1;
                }
                if (t[p2] == '#') 
                {
                    --p2;
                    ++count2;
                }
            }
            while (count1 > 0)
            {
                if (s[p1] != '#')
                {
                    --p1;
                    --count1;
                }
                else 
                {
                    --p1;
                    ++count1;
                }
            }
            while (count2 > 0)
            {
                if (t[p2] != '#')
                {
                    --p2;
                    --count2;
                }
                else 
                {
                    --p2;
                    ++count2;
                }
            }
        }
        if (p1 != -1 || p2 != -1) return false;
        return true;
    }
};
```
