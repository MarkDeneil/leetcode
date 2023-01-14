思想：  
根据 s 的大小来分割，如果 s 为“aabab”，那么**第一层**可以有五次循环：  
第一次循环选择分割"a"，将剩下的作为第二层分割。  
第二次循环选择分割"aa"，将剩下的部分作为第二层分割。  
第三次循环选择分割"aab",将剩下的部分作为第二层分割。  
第四次循环选择分割"aaba",将剩下的部分作为第二层分割。  
第五次循环选择分割"aabab"，剩下空串传递给下一层。  
同样的，第二层、第三层...循环中每层都是这样的思想。  
![131 分割回文串](https://user-images.githubusercontent.com/83362131/212472356-f92b8629-f2f4-429f-8aee-3668ef93caad.jpg)  
该题中，回文串的判断可以借助 string 的反向迭代器来辅助。  
```cpp
// 思想：先分割，每分割完成一组字串，再判断子串是否都是回文的
void backtracking(vector<string> & tmpres, vector<vector<string>> & res, string s, string leftstring,  int leftsize) {
    int size = 0;
    for (auto x : tmpres) {
        size += x.size();
    }
    if (size > s.size()) return;
    if (size == s.size()) {
        for (auto x : tmpres) {
            string tmp(x.rbegin(), x.rend());
            if (x == tmp)
                continue;
            else 
                return;
        }
        res.push_back(tmpres);
    } 

// stirngsize:根据 s 的大小来分割，以确定循环，比如 s 的大小为 5，那么第一层循环就可以设置第一个子串的大小为 1 - 5
    for (int i = 1; i <= leftsize; ++i) {
        string substr(leftstring.begin(), leftstring.begin() + i);
        tmpres.push_back(substr);
        leftstring = string(leftstring.begin() + i, leftstring.end());
        backtracking(tmpres, res, s, leftstring, leftstring.size());
        leftstring = tmpres.back() + leftstring;
        tmpres.pop_back();
    }

}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmpres;
        string leftstring = s;
        int leftsize = s.size();
        backtracking(tmpres, res, s, leftstring, leftsize);
        return res;
    }
};
```
