// 时间复杂度 O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int tag = 1;
        int index = 0;
        vector<int> res(2,0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target && tag == 1)
            {
                res[0] = i;
                tag = 0;
            }
            if (nums[i] == target)
                res[1] = i;
        }
        if (tag == 1) return vector<int>(2,-1);
        return res;
    }
};
