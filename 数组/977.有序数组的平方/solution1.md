## 双指针法
针对题目中的“非递减顺序”排序的整数数组 `nums` ，可以利用双指针法，快慢指针分别指向右左两边，哪一个的平方较大就将其按序放入新的数组中
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> a(size);
        int slow = 0;
        int fast = size - 1;
        int index = size - 1;
        while (fast >= slow)
        {
            int fastval = nums[fast] * nums[fast];
            int slowval = nums[slow] * nums[slow];
            if (fastval >= slowval)
            {
                a[index] = fastval;
                --index;
                --fast;
            }
            else
            {
                a[index] = slowval;
                --index;
                ++slow;
            }
        }
        return a;
    }
};
```

使用三元运算符使代码更简洁
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> a(size);
        int slow = 0;
        int fast = size - 1;
        int index = size - 1;
        while (fast >= slow)
        {
            a[index--] = (nums[fast] * nums[fast] >= nums[slow] * nums[slow]) ? nums[fast] * nums[fast--] : nums[slow] * nums[slow++] ;
        }
        return a;
    }
};
```
