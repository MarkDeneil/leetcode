本题主要考虑三种情况：  
1. 上下坡中有平坡  
2. 当数组只有两个元素时（即数组首尾两端如何判断）
3. 单调中有平坡

情形2中，可以默认最右边是峰谷，然后如果数组第一个元素不等于第二个元素，第一个元素就可以算一个峰谷，之后从第二个元素开始计算。  
这是与代码随想录中不同的思路，情形1、3都相同。  
```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 默认最右边是一个峰值
        int result = 1;
        int prediff = 0;
        int curdiff = 0;

        if (nums.size() <= 1) 
            return nums.size();
        // 第一个结点无法判断是否为峰值，因为其 prediff 无法计算，但是可以发现，只要第一个结点和第二个结点之间不是平的，第一个结点就是峰值，然后就可以从第二个结点开始判断，这里是与代码随想录里情况二不同的地方
        if (nums[0] != nums[1])
            ++result;
        // 从第二个结点开始判断；最后一个结点默认为峰值，不判断
        // 可以看到，如果只有两个元素，那么如果这两个元素是平的，则只有最右边一个峰值；否则有两个峰值。并且不会进入下面的循环
        prediff = nums[1] - nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            curdiff = nums[i + 1] - nums[i]; // 只有两个元素时不会进入循环，因此 nums[i+1] 不会越界
            if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0)) { // 这里两个判断的前者都加上了等于判断，处理情况一，上下坡中有平坡
                prediff = curdiff; // 只有峰值变化时才改变 prediff，处理情况三 单调中有平坡的情况
                ++result;
            }
        } 
        return result;
    }
};
```
