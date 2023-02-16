与 62.不同路径 不同的是，网格中存在障碍物。  
在 62. 中，dp\[i]\[j] 的意义是：到达 (i,j) 有多少条不同的路径。在本题中 dp\[i]\[j] 的意义仍然不变，只是需要考虑，如果遇到了障碍物，那么到达障碍物的路径为 0 条，因为障碍物格不可到达。  
即：如果 (i,j) 是障碍物，则 dp\[i]\[j] 为 0.  
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 有障碍物的格子，到达该格子的路径数为 0，假设第 (i,j) 个格子有障碍物

        // dp[i][j] 代表有多少条路可以到达该元素
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // 当输入为 (1,1) 时，输出为 1，说明初始 dp[0][0] 元素的值为 1
        dp[0][0] = 1; // 机器人初始位置不会有障碍物
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
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
