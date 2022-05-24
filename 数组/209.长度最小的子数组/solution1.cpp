// 暴力解法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sizemin = 100000;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum < target)
            return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int tag = 1;
            sum = 0;
            int size = 0;
            int j;
            for (j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    size = j - i + 1;
                    break;
                }
            }
            if (size < sizemin && size > 0) 
                sizemin = size;
        }
        return sizemin;
    }
};
