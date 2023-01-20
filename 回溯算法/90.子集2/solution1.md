本题即为子集问题+数层去重，注意，数层去重需要对集合进行排序  
```cpp
void backtrack(vector<vector<int>> & res, vector<int> & tmpres, vector<int> & nums, int startIndex) {
    res.push_back(tmpres);

    for (int i = startIndex; i < nums.size(); ++i) {
        if (i > startIndex && nums[i] == nums[i - 1]) {
            continue; 
        }
        tmpres.push_back(nums[i]);
        backtrack(res, tmpres, nums, i + 1);
        tmpres.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmpres;
        int startIndex = 0;
        backtrack(res, tmpres, nums, startIndex);
        return res;
    }
};
```
