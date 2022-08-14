可以模拟螺旋矩阵的路径。初始位置是矩阵的左上角，初始方向是向右，当路径超出界限或者进入之前访问过的位置时，顺时针旋转，进入下一个方向。  
判断路径是否进入之前访问过的位置需要使用一个与输入矩阵大小相同的辅助矩阵，其中的每个元素表示该位置是否被访问过。当一个元素被访问时，将辅助矩阵中的对应位置的元素设为已访问。  
如何判断路径是否结束？由于矩阵中的每个元素都被访问一次，因此路径的长度即为矩阵中的元素数量，当路径的长度达到矩阵中的元素数量时即为完整路径，将该路径返回。  
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int path = 0; // 当 path 值等于元素个数时，循环结束
        vector<vector<int>> tag(m, vector<int>(n, 0)); // 辅助矩阵，元素为 0 表示 matrix 中对应元素还未被访问过
        int i = 0, j = 0; 
        res.push_back(matrix[0][0]);
        tag[0][0] = 1;
        ++path;
        while (path != m * n)
        {
            while (j + 1 < n && tag[i][j + 1] == 0) // 右方向试探，右边元素未超界且未被访问
            {
                j = j + 1;
                res.push_back(matrix[i][j]);
                tag[i][j] = 1;
                ++path;
            }
            while (i + 1 < m && tag[i + 1][j] == 0) // 下方向试探
            {
                i = i + 1;
                res.push_back(matrix[i][j]);
                tag[i][j] = 1;
                ++path;
            }
            while (j - 1 >= 0 && tag[i][j - 1] == 0) // 左方向
            {
                j = j - 1;
                res.push_back(matrix[i][j]);
                tag[i][j] = 1;
                ++path;
            }
            while (i - 1 >= 0 && tag[i-1][j] == 0) // 上方向试探 
            {
                i = i - 1;
                res.push_back(matrix[i][j]);
                tag[i][j] = 1;
                ++path;
            }
        }
        return res;
    }
};
```
建议按照 cral 在螺旋矩阵Ⅱ 题解中的遍历顺序，比较简洁：  
![image](https://user-images.githubusercontent.com/83362131/184521961-3224a126-6ba2-4fb5-b7e2-7c179b1c86ff.png)
