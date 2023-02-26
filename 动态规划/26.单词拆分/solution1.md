本题一个很重要的点是：该题属于完全背包的排列问题。比如 "applepenapple",["apple","pen"]，对解的要求是有顺序的，"apple""pen""apple" 可以，但是 "apple""apple""pen" 或者 "pen""apple""apple" 都不可以，所以需要先遍历背包容量，再遍历物品  
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] 代表 s 的前 i 个字母可以利用字典中出现的单词拼接出 s
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        
        // 字典中的词是元素，能否用元素凑出 s，是完全背包问题。
        // 本题很重要的一个点是该题属于完全背包的“排列”问题，比如 "applepenapple",["apple","pen"]，对解的要求是有顺序的，"apple""pen""apple" 可以，但是 "apple""apple""pen" 或者 "pen""apple""apple" 都不可以，所以需要先遍历背包容量，再遍历物品
        // dp数组推导：判断 dp[j]:如果 dp[i] 为真，且 string(j,i) 正好等于物品 i，则 dp[j] 为真
        for (int j = 0; j <= s.size(); ++j) 
            for (int i = 0; i < wordDict.size(); ++i) {
                if (j >= wordDict[i].size())
                    if (dp[j-wordDict[i].size()] && string(s.begin() + j - wordDict[i].size(), s.begin() + j) == wordDict[i])
                        dp[j] = true;
            }
        return dp[s.size()];
    }
};
```
