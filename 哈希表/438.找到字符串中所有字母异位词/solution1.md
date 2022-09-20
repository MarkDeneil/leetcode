滑动窗口  
窗口内是目前的字符串，用 unordered_map windowmap 记录下来目前的字符及其各字符出现的次数  
移动前窗口的两种情况：  
1. 后窗口 j 出现了不属于 p 中的字符，则把前窗口 i 移动到后窗口之后的一个位置，将 windowmap 置为空。  
2. 把当前后窗口 j 的字符加入目前 windowmap 中后，若与 p 的 map 比较，发现该类字符的个数比 p 的 map 中的该类字符的 map 大，则逐个向后移动前窗口，直到小于 p 的 map 中该类字符的个数。  
移动后窗口：  
逐个移动。
```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() > p.length()) vector<int> ();
        unordered_map<char, int> pmap; // 存储 p 中字符的 map
        for (auto x : p)
        {
            pair<unordered_map<char, int>::iterator, bool> tempp = pmap.insert(make_pair(x, 1));
            if (tempp.second == false)
                ++((*(tempp.first)).second);
        }

        vector<int> res;
        int i = 0, j = 0;
        int tempindex = 0;
        int size = s.size();
        unordered_map<char, int> windowmap;
        for (; j < size; ++j)
        {
            if (pmap.find(s[j]) == pmap.end()) // 出现了不属于 p 中的字符
            {
                i = j + 1;
                windowmap = unordered_map<char, int>();
            }
            else
            {
                pair<unordered_map<char, int>::iterator, bool> tempp = windowmap.insert(make_pair(s[j], 1));
                if (tempp.second == false)
                    ++((*(tempp.first)).second);

                while ((windowmap[s[j]]) > (pmap[s[j]]))
                {
                    --(windowmap[s[i]]);
                    ++i;
                }

                if (windowmap == pmap)
                    res.push_back(i);
            }
            
            
        }
        return res;
    }
};
```
