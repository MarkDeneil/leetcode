与 452.用最少数量的箭引爆气球有类似之处。  
只不过本题要找到重叠区间，并把找到的每个重叠区间删到只剩一个。  

```cpp
bool cmp (const vector<int> & a, const vector<int> & b) {
    return a[0] < b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 与 452.用最少数量的箭引爆气球 重叠区间问题
        // 整体思路：若一块重叠区域上有 n 个重叠区间，那么需要去掉 n-1 个区间；这里要保证，去掉任意 n-2 个区间，剩下的两个区间仍然是重叠的。即，重叠区域中的每个区间都和其他任一个区域有重叠部分。
        // 利用计算重叠区域中最小的右坐标可以做到：假如有区域 [1,2],[1,4],[3,4]，可以看到 [1,2] 和 [3,4] 是非重叠区域，遇到这样的非重叠区域时，一定会进入第一个 if 分支，所以 [3,4] 这个区间不会被计算到这一段的重叠区间内
        sort(intervals.begin(), intervals.end(), cmp);
        int covers = 0; // 前一块区域上有多少个区域重叠了
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= intervals[i-1][1]) {
                res += covers;
                covers = 0; // 计算新的覆盖区域的重叠数
            } else {
                intervals[i][1] = min(intervals[i-1][1], intervals[i][1]);
                ++covers;
            }
        }
        return res + covers; // 如果出循环前执行的是 if 分支，那么 covers 为 0，加上不影响结果；如果是 else 分支，那么最后一块重叠区域的重叠数还没有算，要加上 covers
    }
};
```
