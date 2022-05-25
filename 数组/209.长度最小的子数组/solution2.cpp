// 滑动窗口
// 维持一个滑动窗口，当滑动窗口里的数值大于 sum 时，记录下此时的 size，且滑动窗口的前端向后移动一格
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minsize = 100000;
        int i = 0;
        int sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                minsize = (minsize < (j-i+1) ? minsize : (j-i+1));
                sum -= nums[i];
                ++i;
            }
        }
        if (minsize == 100000)
            return 0;
        return minsize;
    }
};
