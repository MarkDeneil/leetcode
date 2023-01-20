数层去重的第一种方式是首先将数组排序，然后用`if (i > startIndex && nums[i] != nums[i - 1]`  
第二种方式，如果数组不能排序（如本题，不能改变数组元素顺序），但是要求的数组是有序的（总之去重是需要有序条件的），那么可以**在回溯函数的 for 循环前定义**  
`unordered_set<int> unset` 无序集合，是记录本层元素是否重复使用，新的一层uset都会重新定义（清空），所以要知道unset只负责本层！  

在解决该题时，仍然需要用到树层去重，因为 nums 中有重复元素，**当第一层已经选过了一个元素值（假设为 x），那么所有以 x 起始的递增子序列，都在该第一层之后的树枝被选择过了！** 之后如果再在第一层中遇到了元素值为 x 的元素，一定要跳过。  
上面的解释，用例子来讲，是这样，假如有一个数组：  
{....x....x...}  
那么选择第一层选择第一个 x 时，使用第一个 x 之后的元素构造递增子序列；  
第一层选择第二个 x 时，使用第二个 x 之后的元素构造递增子序列，其实用第二个 x 构造的所有子序列，已经被第一个 x 构造的序列包含了，**因为第一个 x 之后的序列是包含第二个 x 之后的序列的**。  
因此，本题需要数层去重。  
**使用 unset 数层去重的方法如下**：  
// 数组中有重复元素，仍然需要去重
// 非有序数组的重复元素去重，注意，如果对普通无序数组使用这种方法去重，仍要对数组排序，否则可能会导致 [1,2,5] [2,1,5] 这样的相同元素出现
// 本题因为要求数组是递增数组，因此不会出现这种情况

void backtrack(vector<vector<int>> & res, vector<int> & tmpres, vector<int> & nums, int startIndex) {
    if (tmpres.size() >= 2)
        res.push_back(tmpres);
    
    //unordered_set<int> uset; 是记录本层元素是否重复使用，新的一层uset都会重新定义（清空），所以要知道uset只负责本层！
    unordered_set<int> unset;

    for (int i = startIndex; i < nums.size(); ++i) {
        if (unset.find(nums[i]) != unset.end())
            continue;
            
        if (tmpres.empty()) {
            tmpres.push_back(nums[i]);
            unset.insert(nums[i]);
            backtrack(res, tmpres, nums, i + 1);
            tmpres.pop_back();
        } else if (nums[i] >= tmpres.back()) {
            tmpres.push_back(nums[i]);
            unset.insert(nums[i]);
            backtrack(res, tmpres, nums, i + 1);
            tmpres.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmpres;
        int startIndex = 0;
        backtrack(res, tmpres, nums, startIndex);
        return res;
    }
};
  ```
