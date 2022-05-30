暴力解法
```cpp
// 暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int i;
        for (i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < size; j++)
                {
                    nums[j-1] = nums[j];
                }
                --size;
                --i; // 注意这里，原来的 nums[i] 已经被覆盖了，现在已经成为 nums[i-1]
            }
        }
        return size;
    }
};
```
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
