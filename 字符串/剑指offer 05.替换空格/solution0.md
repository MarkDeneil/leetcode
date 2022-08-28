```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string ss;
        istringstream is(s);
        char c;
        c = is.get();
        while (c != EOF)
        {
            if (c != ' ')
                ss += c;    
            else
            {
                ss.append("%20");
            }
            c = is.get();
        }
        
        return ss;
    }
};
```
