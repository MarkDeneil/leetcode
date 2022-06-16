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
