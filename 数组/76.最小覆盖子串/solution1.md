滑动窗口  
思想：  
使用 check() 检查是否当前窗口中的字符串(cnt) 覆盖了 目标子串中的字符串(ori)  
当右窗口 r 小于 s.size() 时，进入循环：  
1) 如果右窗口 r 正常行进过程中当前字符是目标子串的字符，则把它加入到当前子串 cnt 中并记录数量（注意，cnt 并不是记录的当前窗口字符串中的所有字符，而是记录当前窗口字符串中是目标子串中的字符的那些字符）  
2) 进入 while 循环：当前窗口字符串 覆盖了 目标子串 中所有字符时，则：、
- 记录下当前的左窗口及当前子串长度（这样就不用单独记录结果子串了，有了左窗口 l 和当前子串长度 len，就可以直接在 s 中寻找出结果串）
- 向前移动左窗口，如果因左窗口移动而被移出当前窗口串的字符是目标子串中的字符，则在 cnt 中去掉该字符，直到当前窗口字符串不能够覆盖目标子串中的所有字符，才退出该层 while 循环  
```cpp
class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};
```
