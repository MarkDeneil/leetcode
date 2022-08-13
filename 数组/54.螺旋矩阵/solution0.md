 思想：利用 i，j 模拟下一个应该输出的矩阵中的位置；利用 offset 代表应该迭代的次数，指针走一圈为一次，一共应该迭代 min{m, n}/2 次  
 同时，若 min{m, n} 为奇数，还应有一行或一列在最后额外输出
 ```cpp
 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int iter = (m > n ? n : m);
        int offset = 0;
        int i = 0;
        int j = 0;
        for (offset = 0; offset < iter/2; offset++)
        {
            i = offset;
            for (j = offset; j < n - offset; j++)
            {
                res.push_back(matrix[i][j]);
            }
            --j;
            for (i = offset + 1; i < m - offset; i++)
            {
                res.push_back(matrix[i][j]);
            }
            --i;
            for (j = n - offset - 2; j >= offset; j--)
            {
                res.push_back(matrix[i][j]);
            }
            ++j;
            for (i = m - offset - 2; i > offset; i--)
            {
                res.push_back(matrix[i][j]);
            }
        }
        if (iter%2 != 0)
        {
            if (m < n)
            {
                for (int j = offset; j < n - offset; j++)
                    res.push_back(matrix[offset][j]);
            }
            else
            {
                for (int i = offset; i < m - offset; ++i)
                    res.push_back(matrix[i][offset]);
            }
        }
        return res;
    }
};
```cpp
