先找到有多少个整的 2k 个字符，再算剩余的  
难点在于下标的计算  
```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int loop = s.size() / (2 * k);
        for (int i = 0; i < loop; ++i)
        {
            for (int j = i * 2 * k, l = i * 2 * k + k - 1; j < l; ++j, --l)
            {
                swap(s[j], s[l]);
            }
        }
        int remain = s.size() % (2 * k);
        remain = (remain >= k ? k : remain);
        for (int i = loop * 2 * k, j = loop * 2 * k + remain - 1; i < j; ++i, --j)
        {
            swap(s[i], s[j]);
        }
        return s;
    }
};
```
