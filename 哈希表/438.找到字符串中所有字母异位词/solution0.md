根据所有字母异位词经过排序后是相同的，采用暴力算法，通过测试用例 33/61  
```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 字母异位词排序后是相同的
        vector<int> res;
        if (s.size() < p.size()) return vector<int>();
        sort(p.begin(), p.end());
        int size = int(p.size());
        string::iterator it;
        int i = 0;
        for (it = s.begin(), i = 0; it + size - 1 != s.end(); ++it, ++i)
        {
            string temp(it, it + size);
            sort(temp.begin(), temp.end());
            if (temp == p)
                res.push_back(i);
        }
        return res;
    }
};
```
