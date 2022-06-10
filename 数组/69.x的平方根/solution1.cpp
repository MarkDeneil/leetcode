// 二分法
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else 
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// 提示：找满足 k*k <= x 的最大值；
// 可以比较 mid * mid 与 x 的大小来判定左右边界的调整
// 目标值范围：[] 区间
