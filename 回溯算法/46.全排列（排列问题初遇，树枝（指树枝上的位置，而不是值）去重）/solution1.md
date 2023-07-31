排列问题的要点就是，**同一个树枝上使用过的元素（注意，不是使用过的相同的值，而是使用过的元素本身）不能再使用了**  
例如，{1,1,2,3} 当第一层选过第一个 1 后，第二层就不可以在选择第一个 1 了，但是仍然可以选择第二个 1.  
可以使用一个 used 数组来记录本树枝上已经用过的元素，此数组需要被回溯！  
最后，排列问题不用startIndex，因为如果一个数组是 {1,2,3} 的话，{1,2,3}{2,1,3} 这种都是其排列。  
```cpp
// 在同一个树枝中，需要记录哪个元素已经用过了，因此 nums 数组有多大，就要用一个多大的 used 数组
// 注意，不是树枝去重，树枝去重是如果第一层用过了1，那么第二层和之后层都不能用1，这样例如 [1,1,2,3] 这样的全排列就不会出现了
// 应该同一个树枝中使用 used 数组记录已经使用过的元素，如 [1,1,2,3] ，用了数组中的第一个 1 后，used 变为 [1,0,0,0]，第一个 1 不能再使用了，但是仍然可以用第二个 1
void backtrack(vector<vector<int>> & res, vector<int> & tmpres, vector<int> & nums, vector<int> & used) {
    if (tmpres.size() > nums.size()) 
        return;
    if (tmpres.size() == nums.size()) 
        res.push_back(tmpres);

    // 排列不使用 startIndex，例如给定数组 [1,2,3]， 第一层选了 [2] 后，第二层可以选 [1]
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] == 1) // 如果 nums[i] 已经使用过，则不再使用 
            continue; 
        used[i] = 1;
        tmpres.push_back(nums[i]);
        backtrack(res, tmpres, nums, used);
        tmpres.pop_back();
        used[i] = 0;
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmpres;
        vector<int> used(nums.size(), 0);
        backtrack(res, tmpres, nums, used);
        return res;

    }
};
```
