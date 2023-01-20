本题和 131.划分子串 的划分思想是相同的，都是划分子串。  
这个问题一开始想复杂了，其实就是将给定的字符串划分为4个部分，然后每个部分的要求：  
1. 不能是以 0 开头的数字，除非本身就是0（可以用这块的size来判定，如果size==1且本身为0，则可以）
2. 每一部分将string转换为数字后，大小在0-255之间。  
```cpp
// string 动态变化，随回溯被切断或者还原，stringsize 是原 string 的长度，用作终止条件判断
void backtrack(vector<vector<string>> & res, vector<string> & tmpres, string & s, int stringsize) {
    // 终止条件
    if (tmpres.size() > 4) {
        return;
    }

    if (tmpres.size() == 4 && s.size() == 0) {
        for (auto x : tmpres) {
            if (x.size() > 1 && x[0] == '0') // 不能以 0 开头 
                return;
            if (atoi(x.c_str()) > 255) {
                return;
            }
        }
        res.push_back(tmpres);
    }    

    for (int i = 1; i <= 3 && i <= s.size(); ++i) {
        string tmpstring(s.begin(), s.begin() + i);
        tmpres.push_back(tmpstring);
        s = string(s.begin() + i, s.end());
        backtrack(res, tmpres, s, stringsize); 
        s = tmpres.back() + s;
        tmpres.pop_back();
    }


}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> res;
        vector<string> final;
        vector<string> tmpres;
        int stringsize = s.size();
        backtrack(res, tmpres, s, stringsize);
        for (auto x : res) {
            string tmps;
            for (auto y : x) {
                tmps += y;
                tmps += '.';
            }

            tmps.erase(tmps.end() - 1, tmps.end());
            final.push_back(tmps);
        }
        return final;
    }
};
```
