// ---------->
// |         |
// |         |
// |         |
// <---------|
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector(n,0));
        int start = 0;
        int offset = 0;
        int loop = n/2; // 循环次数，可以提前算出来
        int mid = n/2; // 当 n 为奇数时，需要填入中间的元素
        int count = 1;
        int i, j;
        while (loop)
        {
            for (i = start; i < n - offset; i++)
            {
                a[start][i] = count;
                ++count;
            }
            for (j = start + 1; j < n - offset; j++)
            {
                a[j][n-offset-1] = count;
                ++count;
            }
            for (i -= 2; i >= start; i--)
            {
                a[n - offset-1][i] = count;
                ++count;
            }
            for(j -= 2; j > start; j--)
            {
                a[j][start] = count;
                ++count;
            }
            --loop;
            ++start;
            ++offset;
        }
        if(n%2 != 0)
        {
            a[mid][mid] = n*n;
        }
        return a;
    }
};
