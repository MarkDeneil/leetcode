数组也是一个简单的哈希表，可以将 a-z 映射到数组的 0-25
```
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 数组也是一个简单的哈希表，将 a-z 映射为数组索引 0-25
        array<int, 26> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (auto x : s)
        {
            ++arr[int(x) - 97];
        }
        for (auto x : t)
        {
            --arr[int(x) - 97];
        }

        for (auto x : arr)
        {
            if (x != 0) return false;
        }
        return true;
    }
};
```
