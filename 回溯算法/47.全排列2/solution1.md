数组中有重复元素，因此数层去重+全排列。  
同时使用 unset 和 used，used 需要回溯  
```cpp
// 对于数组中有重复数字，使用数层去重（对数组排序）
// 对于全排列，使用 used 数组记录每一个树枝中使用过的元素的下标（不是值，是在 nums 数组中的下标，值相同但 nums 数组中下标不同的元素仍然可以使用）
void backtrack(vector<vector<int>> & res, vector<int> & tmpres, vector<int> & nums, vector<int> & used) {
    if (tmpres.size() > nums.size())
        return;
    if (tmpres.size() == nums.size()) 
        res.push_back(tmpres);
    
    unordered_set<int> unset; // 在 for 循环之前定义数层去重
    for (int i = 0; i < nums.size(); ++i) {
        if (unset.find(nums[i]) != unset.end()) // 数层去重
            continue;
        if (used[i] == 1) {
            continue;
        }
        unset.insert(nums[i]); // 数层去重添加

        tmpres.push_back(nums[i]);
        used[i] = 1; 
        backtrack(res, tmpres, nums, used);
        used[i] = 0; // 同一个树枝上的 used 数组要回溯
        tmpres.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 数层去重要排序
        vector<vector<int>> res;
        vector<int> tmpres;
        vector<int> used(nums.size(), 0);
        backtrack(res, tmpres, nums, used);
        return res;
    }
};
```
