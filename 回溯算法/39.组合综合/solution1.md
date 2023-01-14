```cpp
// 参数 startIndex：保证每次循环添加进入 tmpres 中的值都不是前一个值，比如 candidates 是：[4,1,3,...]
// 不能添加进去这样的一个值： 3, 1, ...
// 但是可以添加进这样的值： 3, 3, 3, .....
void backtrack(vector<int> & candidates, int target, vector<int> & tmpres, vector<vector<int>> & res, int startIndex) {
    int sum = 0;
    for (auto x : tmpres) {
        sum += x;
    }
    if (sum == target) {
        res.push_back(tmpres);
        return;
    }
    if (sum > target) {
        return;
    }

    int size = candidates.size();
    for (int i = startIndex; i < size; ++i) {
        tmpres.push_back(candidates[i]);
        backtrack(candidates, target, tmpres, res, i); // 关键点:不用i+1了，表示可以重复读取当前的数
        tmpres.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmpres;
        vector<vector<int>> res;
        int startIndex = 0;
        backtrack(candidates, target, tmpres, res, startIndex);
        return res;
    }
};
```
