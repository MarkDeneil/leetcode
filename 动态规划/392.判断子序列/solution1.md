```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 本题和 1143.最长公共子序列类似
        if (s.size() == 0)
            return true;
        if (t.size() == 0)
            return false;
        if (s.size() > t.size())
            return false;
        // 也可以尝试定义 dp[i][j] 表示 s[0]-s[i] 是否为 t[0]-t[j] 的子序列
        // dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。如果最后 dp[i][j] = s.size()，则说明 s 是 t 的子序列
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
        if (s[0] == t[0])
            dp[0][0] = 1;
        for (int j = 1; j < t.size(); ++j) {
            if ((string(t.begin(), t.begin() + j + 1)).find(s[0]) != string::npos)
                dp[0][j] = 1;
        }
        for (int i = 1; i < s.size(); ++i) 
            for (int j = 1; j < t.size(); ++j) {
                if (s[i] == t[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 如果 s[i] != t[j]，那么 dp[i][j] 就与 dp[i][j-1] 相同
            }
        return s.size() == dp[s.size()-1][t.size()-1];
    }
};
```
