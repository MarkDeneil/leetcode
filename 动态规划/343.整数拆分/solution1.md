dp\[i]:拆分数字 i 可以得到的最大乘积。  
一个 dp\[k] 相当于把 k 拆成了至少两个数的乘积。  
因此 dp\[i] 可以这样得到： 
从 1 到 i 遍历 j：
一个是j * (i - j) 直接相乘。（相当于把 i 拆成两个数）  
一个是j * dp[i - j]，相当于是拆分(i - j)，相当于把 i 拆成 3 个数及以上。  
```cpp
class Solution {
public:
    int integerBreak(int n) {
        // dp[i] : 拆分数字 i 可以得到的最大乘机
        vector<int> dp(n+1,0);
        dp[2] = 1;
        for (int i = 3; i <=n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j])); // 不拆分数字 i-j 和拆分数字 i-j 得到的最大乘机
            }
        }
        return dp[n];
    }
};
```
