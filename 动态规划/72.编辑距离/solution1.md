![IMG_0387(20230311-004528)](https://user-images.githubusercontent.com/83362131/224558241-aa299d20-8f0d-4226-914b-da44346822cd.PNG)
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] 表示将 word1[0]-word1[i] 转换为 word2[0]-word2[j] 所使用的最少操作。注意，虽然本题要求从 word1 转换为 word2，但是我们可以同时改变 word1 和 word2
        if (word1.size() == 0) 
            return word2.size();
        if (word2.size() == 0)
            return word1.size();
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
        if (word1[0] == word2[0])
            dp[0][0] = 0;
        else 
            dp[0][0] = 1; // 替换 word1[0] 为 word2[0]
        for (int i = 1; i < word1.size(); ++i) {
            if (string(word1.begin(), word1.begin() + i + 1).find(word2[0]) == string::npos)
                dp[i][0] = i + 1; // word1 删除 i 个，替换一个
            else
                dp[i][0]= i; // 只需删除 i 个
        }
        for (int j = 1; j < word2.size(); ++j) {
            if (string(word2.begin(), word2.begin() + j + 1).find(word1[0]) == string::npos)
                dp[0][j] = j + 1;
            else
                dp[0][j] = j;
        }

        for (int i = 1; i < word1.size(); ++i) 
            for (int j = 1; j < word2.size(); ++j) {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + 2)));
                }
            }
        return dp[word1.size()-1][word2.size()-1];
    }
};
```
