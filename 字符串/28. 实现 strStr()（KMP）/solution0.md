暴力：  
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 暴力
        int size1 = haystack.size();
        int size2 = needle.size();
        int i = 0, j = 0;
        for (i = 0; i < size1; ++i)
        {
            int temp = i;
            int j = 0;
            while (j != size2 && (haystack[temp] == needle[j]))
            {
                ++temp;
                ++j;
            }
            if (j == size2) return i;
        }
        return -1;
    }
};
```
