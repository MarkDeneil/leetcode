```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] 表示使得 word1[0]-word1[i] 和 word2[0]-word2[j] 相同所需的最小步数
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
        if (word1[0] == word2[0])
            dp[0][0] = 0;
        else 
            dp[0][0] = 2;
        for (int i = 1; i < word1.size(); ++i) {
            if (string(word1.begin(), word1.begin() + i + 1).find(word2[0]) == string::npos)
                dp[i][0] = i + 2;
            else 
                dp[i][0] = i;
        }
        for (int j = 1; j < word2.size(); ++j) {
            if (string(word2.begin(), word2.begin() + j + 1).find(word1[0]) == string::npos)
                dp[0][j] = j + 2;
            else
                dp[0][j] = j;
        }

        for (int i = 1; i < word1.size(); ++i) 
            for (int j = 1; j < word2.size(); ++j) {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j-1]+2, min(dp[i][j-1]+1, dp[i-1][j]+1));
            }
        return dp[word1.size()-1][word2.size()-1];
    }
};
```
