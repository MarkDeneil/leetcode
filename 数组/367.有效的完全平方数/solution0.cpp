// 参考 69.x的平方根
// 二分法
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0;
        long long r = num;
        if (num == 1) return true;
        while ( l <= r)
        {
            long long mid = l + (r - l) / 2;
            if ((long long)mid * mid == num)
                return true;
            else if ((long long)mid * mid < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
