使用 vector<map<char, int>> vec 记录 strs 中每个 string 的 map，然后将 vec 中相同的 map归为一组。  
117/117 测试用例超时  
本题中在写循环时发现，**`continue` 不能跳过 for 循环的表达式 3**  
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>::iterator it;
        vector<map<char, int>> vec;
        for (it = strs.begin(); it != strs.end(); ++it)
        {
            if (*it == "")
                vec.push_back(map<char, int>());
            else
            {
                map<char, int> tempmap;
                for (auto x : *it)
                {
                    pair<map<char, int>::iterator, bool> p = tempmap.insert(make_pair(x, 1));
                    if (p.second == false)
                    {
                        ++((*(p.first)).second);
                    }
                }
                vec.push_back(tempmap);
            }
        }

        vector<vector<string>> resvec;

        while (!vec.empty())
        {
            vector<map<char, int>>::iterator it = vec.begin();
            vector<string>::iterator it1 = strs.begin();

            vector<string> tempstr;
            

            map<char, int> tempmap = *it;
            vec.erase(it);

            tempstr.push_back(*it1);
            strs.erase(it1);

            for (it = vec.begin(), it1 = strs.begin(); it != vec.end();)
            {
                if (*it == tempmap)
                {
                    tempstr.push_back(*it1);
                    it1 = strs.erase(it1);
                    it = vec.erase(it);
                    continue; // 注意，这里不能放在 for 循环的表达式 3 中，因为 continue 不会跳过 for 循环的表达式3
                }
                ++it, ++it1;
            }
            resvec.push_back(tempstr);
        }
        return resvec;
    }
};
```
