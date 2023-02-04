思路：用数组 far[i] 计算出每个字母在 string s 中出现的最远位置，然后：  
从下标 i == 0 开始遍历 s，用时刻记录已遍历的所有字母中出现过的最远的那个位置 max，一旦 i == max ，说明该段可以划分为一段，然后再重新遍历。  
```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 思路：计算出每个字符出现的最远边界；遍历数组，遍历过程中如果遇到了已经遍历的所有字符的最远边界，那么就可以将这个边界作为一个分界点
        // 注意最远边界是实时更新的，遍历的过程中一旦遍历过了一个新的字符，那么也要到达该字符的最远边界
        vector<int> far(26,-1);
        for (int i = 0; i < s.size(); ++i) {
            far[s[i] - 'a'] = i; // 记录的是最远边界的下标
        }
        vector<int> res;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            right = right > far[s[i] - 'a'] ? right : far[s[i] -'a']; 
            if (i == right) { // 当前遍历过的所有元素中，最远边界的下标就是 i 
                res.push_back(right - left + 1);
                left = i + 1;
                right = i + 1;
            }
        }
        return res;
    }
};
```
