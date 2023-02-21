本题与 416.分割等和子集 类似。  
416.是给定一个容量为 sum/2 的背包，问能否装满（即最大能装多少，如果最大装到了 sum/2，则正好装满）  
本题应该把石头尽量分成两堆相等的重量，仍然可以给定一个背包容量为 sum/2 的背包，求该背包最大能装多少价值的石头。  
```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 让石头尽量分成两堆相等的重量
        // 即背包容量为 sum/2 的背包最多能装价值为多少的物品，物品 i 的重量、价值都为 stones[i]
        // dp[i] 表示背包容量为 i 最大能装价值为多少的物品
        int sum = 0;
        for (auto x : stones) {
            sum += x;
        }
        int half = sum / 2;
        vector<int> dp(1501, 0); // 初始化为 0，利用 max 比较时才不会对结果有影响
        dp[0] = 0;
        for (int i = 0; i < stones.size(); ++i) { // 注意，这里是大于等于 0，下标 i 并不是 dp[j] 中的下标 j！
            for (int j = half; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[half] - dp[half];

    }
};
```
