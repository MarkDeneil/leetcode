双指针法：
![15 三数之和](https://user-images.githubusercontent.com/83362131/195069910-e5471d3c-3b7c-4e1c-abe6-3f5dc95c25f1.gif)
首先将 nums 数组排序，然后在下标 0 出 定义指针 i，在 i + 1 处定义 left，在末尾处定义 right；  
如果nums\[i] + nums\[left] + nums\[right] > 0 就说明 此时三数之和大了，因为数组是排序后了，所以right下标就应该向左移动，这样才能让三数之和小一些。  
如果 nums\[i] + nums\[left] + nums\[right] < 0 说明 此时 三数之和小了，left 就向右移动，才能让三数之和大一些，直到left与right相遇为止。  
**当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素的递增，第二个元素是递减的，那么就可以使用双指针的方法，将枚举的时间复杂度从 *O(N^2^)* 减少至 *O(N)*。**  
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; ++i){
            if (nums[i] > 0) break;
            // 接下来去重 a，即如果有 nums = {-1,-1,-1,-1,2} 这样的队列，nums[0],nums[1],nums[4] 即 -1,-1,2 选中作为一个三元组结果后，不能再有其他的 -1,-1,2 （比如 nums[1],nums[2],nums[4] 进入最终结果。
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};
```
