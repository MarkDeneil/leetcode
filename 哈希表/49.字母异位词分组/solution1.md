**因为字母异位词经过排序后是相同的**  
直接定义一个 unordered_map<string, vector<string>>，键是 strs 中的 string 经过排序后的结果，值为字母异位词的 vector<string>  
最后直接将 vector<string> 一个个添加到 vector<vector<string>> res 中即可  
```cpp
  class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 直接创建一个 string 到 vector<string> 的 undered_map；每一个 strs 中的字符串先排序，再插入到 unordered_map 中
        // 使用 undered_map 是因为其速度最快
        unordered_map<string, vector<string>> m;
        for (string & s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            pair<unordered_map<string, vector<string>>::iterator, bool> p = m.insert(make_pair(temp, vector<string>(1, s)));
            if (!p.second)
            {
                ((*(p.first)).second).push_back(s);
            }
        }

        vector<vector<string>> res;
        for (pair<const string, vector<string>> & p : m) // 注意，map 返回的 value_type 中的键是 const 的
        {
            res.push_back(p.second);
        }
        return res;
    }
};
```
