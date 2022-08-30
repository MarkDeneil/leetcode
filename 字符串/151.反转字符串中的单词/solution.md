使用 istringstream 解决。
```cpp
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string word;
        string res;
        int tag = 1;
        while (is >> word)
        {
            if (tag == 1) // 最后一个单词后没有空格
            {
                res += word;
                tag = 0;
            }
            else
            {
                word += ' ';
                res.insert(res.begin(), word.begin(), word.end());
            }
        }
        return res;
    }
};
```
