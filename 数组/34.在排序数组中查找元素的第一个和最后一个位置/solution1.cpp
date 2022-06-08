// 根据题目中的“升序数组”，使用二分法
// 数组中可能会有重复元素，因此需要对二分法进行一些改动
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 二分法，假设 target 在 [left,right] 区间内
        // 能使用二分法是因为 ：升序排列；但是元素可能重复，所以需要稍微改动
        int left = 0;
        int right = nums.size() - 1;
        vector<int> resv(2,-1);
        int res = -1; // 记录二分法找到的 res
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                break;
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;

        }
        if (res == -1) return vector<int>(2,-1);
        resv = {res,res};
        int resl = res;
        int resr = res;
        --resl;
        while (resl >= 0 && nums[resl] == target)
        {
            resv[0] = resl;
            --resl;
        }
        ++resr;
        while (resr <= nums.size() - 1 && nums[resr] == target)
        {
            resv[1] = resr;
            ++resr;
        }
        return resv;
    }
};
