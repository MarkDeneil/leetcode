// target 位于 [] 左闭右闭区间中
class Solution {
public:
    int search(vector<int>& nums, int target) {
         int left = 0;
         int right = nums.size() - 1;
         int middle;
         while (left <= right) // target 位于 [] 区间中，因此当 left == right 时，target 仍有可能在此区间中
         {
             middle = left + (right - left)/2;
             if (target < nums[middle])
                right = middle - 1; 
             else if (target > nums[middle])
                left = middle + 1;
             else 
                return middle;
         }
         return -1;
    }
};
