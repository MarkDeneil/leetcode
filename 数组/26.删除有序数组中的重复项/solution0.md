1. 双指针法
注意双指针的概念：   
快指针：指向新数组的元素  
慢指针：指向新数组应该放入哪个位置  
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 1;
        int size = nums.size();
        while (fast < size)
        {
            if (nums[slow] == nums[fast])
            {
                ++fast;
            }
            else
            {
                ++slow;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
```
