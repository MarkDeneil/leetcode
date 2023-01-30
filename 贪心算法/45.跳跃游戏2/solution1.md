思路：以最小的步数增加覆盖范围：每移动一步，都让移动后的最右端覆盖范围变得尽可能大，直到覆盖范围的最右端大于等于最后一个元素  
如何每移动一步让移动后的覆盖范围右端尽可能大：遍历当前可以移动的范围中的元素，找出 被遍历元素的下标i + 被遍历元素的值nums[i] 最大的那个元素，跳到该元素处  
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        // 思路：以最小的步数增加覆盖范围：每移动一步，都让移动后的最右端覆盖范围变得尽可能大，直到覆盖范围的最右端大于等于最后一个元素
        // 如何每移动一步让移动后的覆盖范围右端尽可能大：遍历当前可以移动的范围中的元素，找出 被遍历元素的下标i + 被遍历元素的值nums[i] 最大的那个元素，跳到该元素处
        int covermax = nums[0]; // 最右端覆盖范围，初始为 nums 中第一个值的大小
        int step = 0;
        int curindex = 0;

        while (covermax < nums.size() - 1) { // 因为生成的测试用例可以到达 nums[n-1]，可以用这个作为循环终止条件
            int tmpcovermax = -1; // 记录等到达的最大覆盖下标
            int tmpmaxindex = -1; // 记录能够使得我们到达最大覆盖下标元素的下标
            for (int i = curindex + 1; i <= curindex + nums[curindex]; ++i) {
                if (i + nums[i] >= tmpcovermax) {
                    tmpcovermax = i + nums[i];
                    tmpmaxindex = i;
                }
            }
            ++step;
            curindex = tmpmaxindex;
            covermax = tmpcovermax;
        }
        // covermax 已经可以到达或超过最大下标，此时有可能要走最后一步
        if (curindex < nums.size() - 1)
            ++step;
        return step;
    }
};
```
