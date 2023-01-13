递归的过程：  
![499007006598780818](https://user-images.githubusercontent.com/83362131/212287412-b0f45615-8d01-4f27-93c2-e08e48ad93be.jpg)
可以抽象为：  
![20201123195223940](https://user-images.githubusercontent.com/83362131/212287579-377e5589-f553-4915-8d39-bb1e0aca4bbd.png)
```cpp
void backtracking(int n, int k, int startIndex, vector<vector<int>> & res, vector<int> & tempres) {
    if (tempres.size() == k) {
        res.push_back(tempres);
        return;
    }

    for (int i = startIndex; i <= n; ++i) {
        tempres.push_back(i);
        backtracking(n, k, i + 1, res, tempres);
        tempres.pop_back();
    }
    return;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tempres;
        backtracking(n, k, 1, res, tempres);
        return res;
    }
};
```
关于代码 for 循环中，backtrecking(n, k, **i + 1**, res, tempres)，i + 1 是因为加入第一层循环已经将 2 （即循环中的 i）放入了tmpres，此时 tmpres：2   
那么接下来只能向 tmpres 中放入 3 或 4（即从 i + 1）开始。  
此外，该代码还可以减枝优化：  
例如在第一层循环中我们已经在 tmpres 中先放入了 4，那么显然没有其他数字可以放了，但要求长度为 2 的结果，所以这条“枝”就可以被减去。  
已经选择的元素个数：path.size();  
还需要的元素个数为: k - path.size();  
在集合n中至多要从该起始位置 : n - (k - path.size()) + 1，开始遍历  
代码如下：  
```cpp
void backtracking(int n, int k, int startIndex, vector<vector<int>> & res, vector<int> & tempres) {
    if (tempres.size() == k) {
        res.push_back(tempres);
        return;
    }

    for (int i = startIndex; i <= n - (k - tempres.size()) + 1; ++i) {
        tempres.push_back(i);
        backtracking(n, k, i + 1, res, tempres);
        tempres.pop_back();
    }
    return;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tempres;
        backtracking(n, k, 1, res, tempres);
        return res;
    }
};
```
