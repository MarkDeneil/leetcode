dp\[i]\[j]:到达第 (i,j) 格有多少种不同的路径  
第 (0,0) 个格子的路径数目为 1（通过在题目中测试输入 \[0,0] = 1）；第一行和第一列的格子，以第一行的格子为例，第一行的每一个格子只能由其左边的格子向右走一步得到，因此到达其左边的格子有多少种路径，达到该格子就有多少种路径；  
到达第 (i,j) 个格子有两种方法：第 (i-1,j) 个格子向下走一步，第 (i,j-1) 个格子向右走一步，因此走到第 (i,j) 个格子的方法数为走到 (i-1,j) 个格子和 (i,j-1) 个格子的方法数之和；  
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] 代表有多少条路可以到达该元素
        vector<vector<int>> dp(m,vector<int>(n,0));
        // 当输入为 (1,1) 时，输出为 1，说明初始 dp[0][0] 元素的值为 1
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0 && j >= 1 && j < n) {
                    dp[i][j] = dp[i][j-1];
                } else if (j == 0 && i >= 1 && i < m) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};
```
