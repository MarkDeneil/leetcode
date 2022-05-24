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
