```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 思路：i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，起始位置从i+1算起，再从0计算curSum。
        // 假设 rest 数组中的一段 [0,...,i,...,j]，若从 0 开始累加，累加到 j 发现和为负，则下标 [1,2,...,j] 都不能作为起点。假设我们判断 i 能否作为起点：
        // 我们能够确定从 [0,...,i-1] 的累加和为正（因为从[0,...,j] 到 j 时 才是第一次累加和为负数），则计算 [i,...,j] 的累加和到 j 时一定为负数，因为计算 [0,...,j] 累加和的过程中，计算到下标 i 时已经给 i 加上了一个非负的累加和，比直接从 i 开始计算累加和要大，在这种情况下计算到 j 时累加和都为负数，那么直接从 i 开始计算累加和也一定为负数 
        vector<int> rest(gas.size(), 0);
        int sum = 0;

        for (int i = 0; i < gas.size(); ++i) {
            rest[i] = gas[i] - cost[i];
            sum += rest[i];
        }
        if (sum < 0) 
            return -1;

        // 已经确定一定有一个下标可以走完全程
        sum = 0;
        int resindex = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += rest[i];
            if (sum < 0) {
                resindex = i + 1;
                sum = 0;
            }
        }

        if (resindex < gas.size())
            return resindex;
        else 
            return -1;
    }
};
```
