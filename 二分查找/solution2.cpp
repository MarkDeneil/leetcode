// target 位于 [) 左闭右开区间中
class Solution {
public:
    int search(vector<int>& nums, int target) {
         int left = 0;
         int right = nums.size(); // 此时不能写为 right = nums.size() - 1,因为假设 target 位于 [) 区间中，最开始时这样设相当于最后一个元素不在 target 区间中
         int middle;
         while (left < right)
         {
             middle = left + (right - left)/2;
             if (target < nums[middle])
                right = middle; //这里注意不是 right = middle - 1；
             else if (target > nums[middle])
                left = middle + 1;
             else 
                return middle;
         }
         return -1;
    }
};
