背包容量有两个维度  
```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 问题：背包容量为 m 个 0 和 n 个 1 的背包最多能装多少 strs 中的元素
        // dp[i][j]：背包容量为 i 个 0 和 j 个 1 的背包最多能装多少个 strs 中的元素
        // 相当于有两个背包容量：m 和 n，价值和重量相当于 strs 元素中的 onenum 和 zeronum，元素为 strs 中的元素，每个元素只能用一次  
        // 先遍历元素 k，再便利背包容量 i 和 j，使用滚动数组，那么只需便利 i 和 j
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;
        for (int k = 0; k < strs.size(); ++k) {
            int onenum = 0, zeronum = 0;
            for (string::iterator it = strs[k].begin(); it != strs[k].end(); ++it) {
                if (*it == '1')
                    ++onenum;
                else 
                    ++zeronum;
            }
            for (int i = m; i >= zeronum; --i) {
                for (int j = n; j >= onenum; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeronum][j-onenum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```
