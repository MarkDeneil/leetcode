dp[i][j] 表示 长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]    
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] 表示 长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        
        if (text1[0] == text2[0]) dp[0][0] = 1;
        for (int i = 1; i < text1.size(); ++i) {
            string s(text1.begin(), text1.begin() + i + 1);
            if (s.find(text2[0]) != string::npos)
                dp[i][0] = 1;
        }
        for (int j = 1; j < text2.size(); ++j) {
            string s(text2.begin(), text2.begin() + j + 1);
            if (s.find(text1[0]) != string::npos)
                dp[0][j] = 1;
        }

        for (int i = 1; i < text1.size(); ++i) {
            for (int j = 1; j < text2.size(); ++j) { 
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};
```
