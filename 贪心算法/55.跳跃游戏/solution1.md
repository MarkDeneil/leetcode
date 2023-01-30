思路：将该问题转化为 为跳跃覆盖范围究竟可不可以覆盖到终点。  
只要当前 index 没有超过最大覆盖范围右端，就可以一直向右遍历，在向右遍历的过程中同时更新最大覆盖范围的右端。 
结束：直到最大覆盖范围到达或了数组最后一个元素下标（成功），或者当前遍历元素下标超过了最大覆盖范围右端（失败）  
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 更简单地思想：只更新能够覆盖地最大范围地右端
        // 最大覆盖范围右边界 的所有之前的元素，都是可以访问的
        int i = 0;
        int covermax = 0;
        while (i <= covermax) {
            if (covermax >= nums.size() - 1) // 达到题目要求
                return true;
            if (i + nums[i] > covermax)
                covermax = i + nums[i];
            ++i;
        }
        return false;
    }
};
```
