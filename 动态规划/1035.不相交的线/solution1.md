与 1143.最长公共子序列 类似。本题也是求最长的（相对位置不变）的公共子序列  
dp[i][j] 表示截止到 nums1[i] 和 nums2[j] 最长的公共子序列  
```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // 与 1143.最长公共子序列 类似。本题也是求最长的（相对位置不变）的公共子序列
        // dp[i][j] 表示截止到 nums1[i] 和 nums2[j] 最长的公共子序列
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        for (int i = 0; i < nums1.size(); ++i) {
            vector<int>::iterator it;
            if ((it = find(nums1.begin(), nums1.begin() + i + 1, nums2[0])) != nums1.begin() + i + 1)
                dp[i][0] = 1;
        }
        for (int j = 0; j < nums2.size(); ++j) {
            vector<int>::iterator it;
            if ((it = find(nums2.begin(), nums2.begin() + j + 1, nums1[0])) != nums2.begin() + j + 1)
                dp[0][j] = 1;
        }
        for (int i = 1; i < nums1.size(); ++i) {
            for (int j = 1; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[nums1.size() - 1][nums2.size() - 1];
    }
};
```
