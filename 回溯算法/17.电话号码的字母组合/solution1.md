示意图：  
![20201123200304469](https://user-images.githubusercontent.com/83362131/212290504-3fe4e61e-3d13-43b7-a96c-933f61e6b15f.png)
该题中，要根据当前层对应的 digits 中是什么数字，来决定当前层有几层循环。如果 digits 中第一个数字为 2，那么当前层就有 3 个循环，每个循环开始分别把 'a','b','c' 赋给tmpres  
```cpp
// 如果是 “134”,那么结果集合中的所有字符串都是 3 位的，因此递归时就计算 tmpres 的长度
// 参数：1.最终的字符串长度，用来判断是否结束 2.存放字符串的临时结果 tmpres 3.最终结果集合 res
void backtrack(int stringsize, string & tmpres, vector<string> & res, string digits, vector<string> & vs) {
    if (tmpres.size() == stringsize) {
        res.push_back(tmpres);
        return ;
    }
    
    // 如果 digits 中第一个数字是2，那么第一层就对应数字2，循环就应该循环 3 次，每次循环分别把字符 "a", "b", "c" 赋给 tmpres 的第一位
    // 接下来的循环也是如此
    // 循环次数可以用 tmpres.size() 判断，tmpres.size() == 0 时，说明是第一次循环,...

    // 取当前层对应 digits 中的数字
    int i = tmpres.size() + 1;
    string snum (digits.begin() + i - 1, digits.begin() + i);
    int num = atoi(snum.c_str());

    // 取对应数字对应的 vs 中的字符串
    string curstring = vs[num - 2]; // -2 是因为数字 1 不对应 vs 中的字符串

    // 对应的 vs 中的字符串有多大，本次循环就循环几次，每次循环回溯地向 tmpres 中添加对应字符
    int curstringsize = curstring.size();
    for (int index = 0; index < curstringsize; ++index) {
        tmpres.push_back(curstring[index]);
        backtrack(stringsize, tmpres, res, digits, vs);
        tmpres.pop_back();
    }


}


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> vs = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string tmpres;
        int stringsize = digits.size();
        backtrack(stringsize, tmpres, res, digits, vs);
        return res;
    }
};
```
