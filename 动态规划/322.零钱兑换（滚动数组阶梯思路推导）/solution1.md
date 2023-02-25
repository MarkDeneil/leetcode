1. 使用滚动 dp 数组  
构造滚动 dp 数组的思路：  
使用一维数组求解的思路：其实只要将 dp[j] 往前推一步就可以了。这样就能从 dp[0] 来推出所有的结果。如何往前推一步？  
可以假设背包中现在有一个元素，那么该元素可能是从 coins[0] ~ coins[coins.size()-1] 的所有元素，只需要把这些元素都考虑到，那么  
dp[j] 和 dp[j] 往前推一步的关系就找到了  
以本题为例，需要找到 凑成总金额所需的最少的硬币个数，dp[j] 代表凑满总金额 j 所需的最少的硬币个数，往前推一步，假设背包中已经有了  
一个硬币，那么该硬币可能是 coins[0] ~ coins[coins.size()-1] 中所有的硬币，假设为硬币 coins[i]  
当背包里有一个 coins[i] 时，凑满总金额 j 所需的最少的硬币个数等于 dp[j - coins[i]] + 1；加的这个 1 就是硬币 coins[i]  
因为要求最少的硬币个数，所以 dp[j] 和 dp[j - coins[i]] + 1 两者取较小者，初始化时 dp 数组中的元素应该初始化的大一点  

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题；因为本题求的是凑成总金额所需的最少的硬币个数，所以不需要区分组合或排列，按照先元素再背包容量求解
        // dp[j] 表示凑满总金额 j 需要最少的硬币个数
        vector<unsigned int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // 凑成金额 0 ，不用凑
        for (int i = 0; i < coins.size(); ++i) 
            for (int j = coins[i]; j <= amount; ++j) 
                if (j > 1) // dp[1] 已经初始化过了
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
        return dp[amount] == INT_MAX ? -1 : dp[amount];

        // 使用一维数组求解的思路：其实只要将 dp[j] 往前推一步就可以了。这样就能从 dp[0] 来推出所有的结果。如何往前推一步？
        // 可以假设背包中现在有一个元素，那么该元素可能是从 coins[0] ~ coins[coins.size()-1] 的所有元素，只需要把这些元素都考虑到，那么
        // dp[j] 和 dp[j] 往前推一步的关系就找到了
        // 以本题为例，需要找到 凑成总金额所需的最少的硬币个数，dp[j] 代表凑满总金额 j 所需的最少的硬币个数，往前推一步，假设背包中已经有了
        // 一个硬币，那么该硬币可能是 coins[0] ~ coins[coins.size()-1] 中所有的硬币，假设为硬币 coins[i]
        // 当背包里有一个 coins[i] 时，凑满总金额 j 所需的最少的硬币个数等于 dp[j - coins[i]] + 1；加的这个 1 就是硬币 coins[i]
        // 因为要求最少的硬币个数，所以 dp[j] 和 dp[j - coins[i]] + 1 两者取较小者，初始化时 dp 数组中的元素应该初始化的大一点
    }
};
```

2. 二维 dp 数组：dp\[i]\[j] 表示使用 coins 0 ~ i 凑成总金额 j 所需的最少的硬币个数
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题
        // dp[i][j] 表示使用 coins 0~i 凑成总金额 j 所需要的最少的硬币个数
        int size = coins.size();
        vector<vector<unsigned long long >> dp(size + 1, vector<unsigned long long>(amount + 1, 2147483647));
        for (int i = 0; i < size; ++i) { // 初始化第一列为 0
            dp[i][0] = 0;
        }
        for (int j = 0; j <= amount; ++j) { // 初始化第一行，只有容量大于 0 为 coins[0] 的倍数时，才初始化为 j/coins[0]
            if (j % coins[0] == 0)
                if (j != 0)
                    dp[0][j] = j / coins[0];
        }

        for (int i = 0; i < size; ++i) 
            for (int j = 0; j <= amount; ++j) {
                if (j < coins[i]) { // 目前的容量放不下一个 coins[i]
                    if (i >= 1)
                        dp[i][j] = dp[i-1][j];
                } else { // 目前的容量放得下一个 coins[i]
                    // 如果不放，dp[i][j] = dp[i-1][j]
                    // 如果放，dp[i][j] = dp[i][j - coins[i]] + 1，注意等号右侧下标为 i，因为物品 i 可以被使用无限次
                    if (i >= 1)
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1); // 因为要求所需的最少的硬币个数，取两者较小者
                        // 上述 dp 数组可以使用滚动数组的思想，压缩成一维数组
                }
            }
        return dp[size-1][amount] == 2147483647 ? -1 : dp[size-1][amount];

        
        
    }
};
```
