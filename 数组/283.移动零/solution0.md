1. 双指针法  
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int size = nums.size();
        while (fast < size)
        {
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
            }
            else
            {
                --slow;
            }
            ++fast;
            ++slow;
        }
        int res = slow;
        for (int i = slow; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
```
