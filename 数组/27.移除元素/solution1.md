下面的这种方法不可行，会出现异常
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int size = nums.size();
        int i;
        for (i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i; j < size - count - 1; j++) // 定义一个变量count
                {
                    nums[j] = nums[j+1];
                }
                ++count;
                --i;
            }
        }
        return size - count;
    }
};
```
