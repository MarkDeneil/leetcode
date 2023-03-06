dp[i][j] ：以下标i为结尾的A，和以下标j为结尾的B，最长重复子数组长度为dp[i][j]。 （特别注意： “以下标i为结尾的A” 标明一定是 以A[i]为结尾的字符串 ）  
```cpp
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] ：以下标i为结尾的A，和以下标j为结尾的B，最长重复子数组长度为dp[i][j]。 （特别注意： “以下标i为结尾的A” 标明一定是 以A[i]为结尾的字符串 ）
        int res = 0;
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        // 初始化
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                res = 1;
            }
                
        }
        for (int j = 0; j < nums2.size(); ++j) {
            if (nums1[0] == nums2[j]) {
                dp[0][j] = 1;
                res = 1;
            }
        }

        for (int i = 1; i < nums1.size(); ++i) {
            for (int j = 1;j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > res)
                    res = dp[i][j];
            }
        }
        return res;
    }
};
```
