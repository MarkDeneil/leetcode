题目特征：
1. 无重复元素
2. 升序排列数组   
使用二分查找
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int size = nums.size();
        int right = size - 1;
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return left;
    }
};
```
