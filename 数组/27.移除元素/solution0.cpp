// 思想：将值为 val 的元素直接与数组最后的元素换位置；因此，需要从后往前遍历
// 此解法建立在 ：数组中元素的顺序可以改变的条件下
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = nums.size() - 1;
        for (int i = index; i >= 0; i--)
        {
            if (nums[i] == val)
            {
                int t = nums[i];
                nums[i] = nums[index];
                nums[index] = t;
                --index;
            }
        }
        return index + 1;
    }
};
