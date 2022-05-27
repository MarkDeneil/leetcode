class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector(n,0));
        int startx = 0;
        int starty = 0;
        int offset = 1;
        int loop = n/2; // 循环次数，可以提前算出来
        int mid = n/2; // 当 n 为奇数时，需要填入中间的元素
        int count = 1;
        int i, j;
        while (loop)
        {
            for (i = startx; i < n - offset; i++)
            {
                a[startx][i] = count;
                ++count;
            }
            for (j = starty; j < n - offset; j++)
            {
                a[j][n-offset] = count;
                ++count;
            }
            for (; i > startx; i--)
            {
                a[n-offset][i] = count;
                ++count;
            }
            for(; j > starty; j--)
            {
                a[j][starty] = count;
                ++count;
            }
            --loop;
            ++startx;
            ++starty;
            ++offset;
        }
        if(n%2 != 0)
        {
            a[mid][mid] = n*n;
        }
        return a;
    }
};
