这一题相对于 77.组合 来说，本质上是在终止条件上多加了判断。  
```cpp
// 参数：用一个 vector<int> 记录当前存的结果，一个 startIndex 用来控制 for 循环的起点，如第一层遍历中 i 取 1，2，3，...；第二层遍历 i 就应该从 2，3，... 开始取了
void backtrack(vector<vector<int>> & res, vector<int> &tmpres, int k, int n, int startIndex) {
    // 如果 tmpres的数量到了 k，则终止；终止前如果和为 n，则将其加入 res
    if (tmpres.size() == k) {
        int sum = 0;
        for (vector<int>::iterator it = tmpres.begin(); it != tmpres.end(); ++it) {
            sum += *it;
        }
        if (sum == n)
            res.push_back(tmpres);
        return;
    }

    // 回溯过程
    for (int i = startIndex; i <= 9 - (k - tmpres.size()) + 1; ++i) {
        tmpres.push_back(i);
        backtrack(res, tmpres, k, n, i + 1);
        tmpres.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmpres;
        int startIndex = 1;
        backtrack(res, tmpres, k, n, startIndex);
        return res;
    }
};
```
