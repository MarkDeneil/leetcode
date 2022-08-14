按照 cral 在螺旋矩阵Ⅱ中的顺序来遍历，会简洁很多;  
该题目中矩阵边长可以为 0，因此有判空操作：  
使用 vector 的 `empty()` 函数判空，返回空的 vector 元素：
`return {};`  
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {}; // 一个注意点是本题中矩阵边长可以为 0，可以用 vector 的 empty() 来判断
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int iter = (m > n ? n : m) / 2;
        int i = 0, j = 0;
        int offset = 0;
        while (iter != 0)
        {
            // 按照 cral 螺旋矩阵Ⅱ 教程中的顺序来，该题比较简洁
            for (j = offset; j < n - offset - 1; ++j)
            {
                res.push_back(matrix[offset][j]);
            }
            for (i = offset; i < m - offset - 1; ++i)
            {
                res.push_back(matrix[i][j]);
            }
            for (; j > offset; --j)
            {
                res.push_back(matrix[i][j]);
            }
            for (; i > offset; --i)
            {
                res.push_back(matrix[i][j]);
            }

            ++offset;
            --iter;
        }
        if ((m > n ? n : m) % 2 != 0)
        {
            if (m > n)
            {
                for (i = offset; i < m - offset; ++i)
                {
                    res.push_back(matrix[i][offset]);
                }
            }
            else
            {
                for (j = offset; j < n - offset; ++j)
                {
                    res.push_back(matrix[offset][j]);
                }
            }
        }
        return res;
    }
};
```
