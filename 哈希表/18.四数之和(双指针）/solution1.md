和 15.三数之和类似，只不过比三数之和多了一个循环  
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i){
            // 第一个元素去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); ++j){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l){
                    if ((long)nums[i] + nums[j] + nums[k] + nums[l] > target) --l;
                    else if ((long)nums[i] + nums[j] + nums[k] + nums[l] < target) ++k;
                    else {
                        vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(temp);
                        while (k < l && nums[k + 1] == nums[k]) ++k;
                        while (k < l && nums[l - 1] == nums[l]) --l;
                        ++k;
                        --l;
                    }
                }
            }
        }
        return res;
    }
};
```
