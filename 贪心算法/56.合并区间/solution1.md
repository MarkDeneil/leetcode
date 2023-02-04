与 452.用最少数量的箭引爆气球 类似。只不过 452. 是寻找最小的重叠区间，而本题是寻找范围最大的重叠区间。  
先对区间排序，然后遍历区间，并时刻记录当前重叠区间**右边界的最大值**  
当当前遍历区间 i 的左边界大于上一个重叠区间右边界的最大值时，说明上一个重叠区间可以合并了，然后从本区间开始重新计算重叠区间；  
当当前遍历区间 i 的左边界小于等于一个重叠区间右边界的最大值时，说明区间仍然属于上一个重叠区间中，就把上一个重叠区间右边界的最大值设为：本区间右边界值和上一个重叠区间右边界最大值中的较大者。  
```cpp
bool cmp(const vector<int> & a, const vector<int> & b) {
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 与 452.用最少数量的箭引爆气球 435.无重叠区间 类似；只不过前两题是求最小覆盖区间，本题是求最大覆盖区间
        // 思路，维护一个最大重叠区间[left,right],遍历 intervals，如果本次遍历的区间的 interval[i][0] 小于 right 且 interval[i][1] 大于 right，那么将 right 更新为 interval[i][1]；
        // 否则，说明该区间与之前维护的最大重叠区间[left,right] 没有重叠，可以将 [left,right] 假如 res
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int initialindex = 0;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > right) { // 确定了一个区间
                vector<int> tmp = {left, right};
                res.push_back(tmp);
                left = intervals[i][0];
                right = intervals[i][1];
            } else { // intervals[i][0] <= right
                right = (intervals[i][1] >=right ? intervals[i][1] : right); // 这里与 452. 43. 不同，本题维护最大区间
            }
        }
        
        vector<int> tmp = {left, right};
        res.push_back(tmp);
        return res;
    }
};
```
