重叠区间问题首先要对区间排序（一般按照第一个元素排序即可）  
本题思路：依次遍历气球，观察本气球与上一个气球的关系，如果  
1. 本气球的左边界**大于**上一个**重叠区间的最小右边界**，则说明要用一个箭射掉上一个重叠区间，并从这个气球开始重新计算重叠区间。  
2. 本气球的左边界**小于**上一个气球的最小右边界，说明本气球仍然可以算在上一个重叠区域中，就把上一个重叠区域的最小右边界设为：本气球的右边界和上一个重叠区域最小右边界的较小者。  
这样做的思路是：如果气球重叠了，重叠气球中右边边界的最小值 之前的区间一定需要一个弓箭。  
```cpp
bool cmp (const vector<int> & a, const vector<int> & b) {
    return a[0] < b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // [1,6] [2,8] [7,12] [15,16]
        if (points.size() == 1) return 1;
        sort(points.begin(), points.end(), cmp);
        int res = 0;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > points[i-1][1]) { 
                ++res; // 此时不应该更改最小边界了，而是应该计算新的最小边界
            }
            else { // 第 i 个和第 i-1 个气球重叠
                points[i][1] = min(points[i][1], points[i-1][1]); // 将当前第 i 个气球的右边界变为当前遍历过的最小边界，如果下一个气球的左边界大于这个值，则应该射一箭              
            }
        }
        ++res; // 如果最后一个 i 进入了 if 分支，那么射出的箭也是引爆上一个重叠区域的箭；如果进入了 else 分支，那么本次重叠区域还未引爆；两种情况都应该将箭头数加一
        return res;
    }
};
```
```cpp
bool sortpoints(const vector<int> & v1, const vector<int> & v2) { // 按照最小右边界排序
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    return v1[1] < v2[1];
} 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), sortpoints);
        int res = 1;
        int r = points[0][1]; // 记录最左边重叠区间的最小右边界
        for (int i = 0; i < points.size(); ++i) { // 最重要的点，不一定要真的去掉 vector 中的元素，而只是遍历一遍
            if (points[i][0] > r) {
                ++res;
                r = points[i][1];
            }
        }
        return res;
    }
};
```
