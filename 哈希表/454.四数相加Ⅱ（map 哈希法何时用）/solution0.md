BF: 超时；与 1.两数相加 想法类似，哈希法可以在此使用  
```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 最起码哈希法可以这样用：第一个数组的元素遇到就加入到 map 中，遍历第 2，3，4 个数组，每一次遍历看 map 中有无 target-num2-num3-num4
        unordered_multiset<int> m;
        for (int i = 0; i < nums4.size(); ++i)
        {
            m.insert(nums4[i]);
        }
        int count = 0;
        int i = 0, j = 0, k = 0;
        for (i = 0; i < nums1.size(); ++i)
            for (j = 0; j < nums2.size(); ++j)
                for (k = 0; k < nums3.size(); ++k)
                {
                    count += m.count(0 - nums1[i] - nums2[j] - nums3[k]);
                }
        return count;
    }
};
```
