![3DE1E31F98720F7D69A153627612088A](https://user-images.githubusercontent.com/83362131/224558136-e8333b43-e253-4ef0-81e9-89aedceeb578.png)
![272AF6DB751E3FFEF8C04E918B7EE245](https://user-images.githubusercontent.com/83362131/224558143-264d04b7-00e4-4826-a388-a46a714d8fc1.png)
```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size()  == 0)
            return 0;
        if (s.size() < t.size())
            return 0;
        // dp[i][j] 表示 s[0]-s[i] 中出现 t[0]-t[j] 这个序列的次数
        vector<vector<unsigned long long>> dp(s.size(), vector<unsigned long long>(t.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            int count = 0;
            char c = t[0];
            for (char x : string(s.begin(), s.begin() + i + 1))
                if (x == c)
                    ++count;
            dp[i][0] = count;
        }
        for (int i = 1; i < s.size(); ++i) 
            for (int j = 1; j < t.size(); ++j) {
                if (s[i] == t[j])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        return dp[s.size()-1][t.size()-1];

    }
};
```
