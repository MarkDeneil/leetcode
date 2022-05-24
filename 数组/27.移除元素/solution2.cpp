// 双指针法，可以保证移除元素后数组的剩余元素的顺序
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastpointer = 0;
        int slowpointer = 0;
        for (fastpointer = 0; fastpointer < nums.size(); fastpointer++)
        {
            if(nums[fastpointer] != val)
            {
                nums[slowpointer] = nums[fastpointer];
                slowpointer++;
            }
        }
        return slowpointer;
    }
};
