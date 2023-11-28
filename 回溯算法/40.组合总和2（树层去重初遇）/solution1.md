**可以去重的特点：candidates集合中有相同的数字**  
首先题目要求集合中的每个数字都只能使用1次，但**集合中有相同的数字**,这就可以去重了，例如：  
candidates = \[1,2,3,4,5,1]  
在查找总和为 target 的组合时，普通做法的第一层循环可以会以 candidates 的大小为循环，因此第一层循环分别选 1，2，3，4，5，1  
但是，选择第一个 1 和最后一个 1 时，求解处的组合是一样的！  
当第一层选择**第一个1**时，第二、三...层循环就利用剩下的\[2,3,4,5,1]集合中的数字组成组合，直到该组合和为target  
当第一层选择**最后一个1**时，第二、三...层循环就利用剩下的\[1,2,3,4,5]集合中的数字组成组合，直到该组合和为target  
可以看出，这样两个第一层循环都选1时求出的组合是一样的！
因此需要**去重**，即**不管 candidates 中开始有多少个1，在所有的第一层循环中只选择一次1，之后再在第一层循环中遇到1时，就跳过**  
同样的，在每一层循环中，都要跳过相同的数，跟上面同样的道理。  
因此，为了达到在同一层循环中方便跳过相同的数，就需要对数组**排序**，即**去重需要排序**。  
```cpp
// 终止条件：当前 tmpres 中的和大于或者等于 target
void backtracking(vector<int> & candidates, int target, vector<int> & tmpres, vector<vector<int>> & res, int startIndex) {
    int sum = 0;
    for (auto x: tmpres) {
        sum += x;
    }
    if (sum == target) {
        for (auto x : res) {
            if (tmpres == x) // 重复的数组，例如 [1,7], [7,1] 不再加入 res 中
                return; 
        }
        res.push_back(tmpres);
        return ;
    }
    if (sum > target) {
        return ;
    }
    int size = candidates.size();
    for (int i = startIndex; i < size; ++i) {
        // 去重，比如，如果在本次第一层已经选过了 1 这个数，那么“以本次第一层循环开头的循环过程中）所有以 1 开头的答案都已经找出来了，那么在之后的第一层循环中，就不能再选 1 了（注意，此时答案数组中是允许重复的，比如1123这个结果，但这个结果中第一个 1 是在第一层循环里选的，第二个1不是在第一层循环中选的.即，如果某个第一层循环选了一个 1，那么后面所有的第一层循环中，就不选 1 了）。
        //同样的，在第二层时（此时在某个第一层的逻辑中，即 tmpres 的第一个数已经暂时确定了，假如是 i），如果已经选过了 2 这个数，此时 tmpres 为 [i,2]，那么“在本次以 i 为第一层循环， 2 为第二次循环主导的循环过程中”所有以 [i,2] 开头的结果已经都找出来了，那么在以 i 为第一层循环的循环过程中，之后的第二层循环就不再选 2 了。
        // 代码随想录中使用 uesd 数组树层去重也是这个思想。candidate[i] == candidate[i - 1] （假如为值x）说明本层中遇到前后两个一样的数 x 了，而 used[i-1] == false 说明目前的 candidate[i] 已经不是本层第一个使用的 x 了（candidate[i-1]或者更之前的才是第一个），那么就不用再在本层选这个 x 了。而如果 used[i-1] == true，说明这不是同一层使用的 x，而是同一树枝中使用的 x（因为这个 used 数组也是会回溯的，从第一个第一层循环到第二个第一层循环之间，所有的 used 数组中的数都被置 false。只有同一树枝中使用的 x，used 数组中还没回溯结束将 used 置为 false。
        if (i >= startIndex + 1) 
            if (candidates[i] == candidates[i - 1])
                continue;
        tmpres.push_back(candidates[i]);
        backtracking(candidates, target, tmpres, res, i + 1); // 集合中的每个数只能使用一次，因此是 i + 1
        tmpres.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 树层去重的话，需要对数组排序
        vector<vector<int>> res;
        vector<int> tmpres;
        int startIndex = 0;
        backtracking(candidates, target, tmpres, res, startIndex);
        return res;
    }
};
```
