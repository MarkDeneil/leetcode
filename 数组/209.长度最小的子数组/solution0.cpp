// 暴力解法，时间太长未通过
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum < target) return 0;
        
        int sizemin = 100000;
        int size = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            size = 0;
            sum = 0;
            while (sum < target)
            {
                sum += nums[j];
                ++size;
                j += 1;
            }
            if (size < sizemin)
                sizemin = size;
        }
        return sizemin;
    }
}; 
