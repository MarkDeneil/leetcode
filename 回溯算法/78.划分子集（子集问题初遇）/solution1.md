如果把子集问题、组合问题、分割问题都抽象为一棵树的话，那么组合问题和分割问题都是收集树的叶子节点，而子集问题是找树的所有节点！  
该问题有两个要点，假设找{1,2,3}的子集：    
1. 类似 {1,2} 和 {2,1} 重复了，因此本题要使用 startIndex，即第一层为 2 时，之后第二层、第三层...2 之前的元素不能再选了
2. 同一个树枝上，选过的元素不可以再选了，比如第一层选了1，第二层就不可以再选1了，可以用一个全局的 used 数组来实现
（注意，这里使用 used 数组不是数层去重，也不是树枝去重，而是同一个树枝上已经用过的元素不能再用了，如 {1,1,2,3}，第一层使用了第一个1，那么第二层仍然可以使用第二个1，但是不能再使用第一个1了）
```cpp
// 不能取重复元素
void backtrack(vector<vector<int>> & res, vector<int> & tmpres, vector<int> & nums, int startIndex, vector<int> & used) {
    res.push_back(tmpres); // 树中所有结点都加入
    
    for (int i = startIndex; i < nums.size(); ++i) {
        if (used[i] == 0) {
            tmpres.push_back(nums[i]);
            used[i] = 1;
            backtrack(res, tmpres, nums, i + 1, used);
            tmpres.pop_back();
            used[i] = 0;
        }
        
    }
    
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmpres;
        vector<vector<int>> res;
        int startIndex = 0;
        vector<int> used(nums.size(), 0);
        backtrack(res, tmpres, nums, startIndex, used);
        return res;
    }
};

```
