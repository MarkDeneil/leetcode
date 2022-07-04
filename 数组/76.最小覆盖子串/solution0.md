暴力：  
思想：  
遍历 s 中的每个字符，每次遍历都找出从当前字符开始的包含子串 t 的字符串  
超出时间限制，265/266 个测试用例  
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int sizet = t.size();
        int sizes = s.size();
        string res;
        int ressize = 10001;

        for (int i = 0; i < sizes; i++)
        {
            char * arrayt = new char[sizet + 1];
            for (int j = 0; j < sizet; j++)
            {
                arrayt[j] = t[j];
            }
            arrayt[sizet] = '\0';
            
            int length = strlen(arrayt);

            vector<char> q; // 暂时存放结果的字符串
            int tempsize = 0;
            
            for (int j = i; j < sizes; j++)
            {
                q.push_back(s[j]);
                ++tempsize;
                for (int p = 0; p < length; p++)
                {
                    if (arrayt[p] == s[j])
                    {
                        for (int q = p + 1; q <= length; q++)
                       {
                           arrayt[q - 1] = arrayt[q];
                       }
                       break; // 当前的字符 q[j] 只能匹配 arrayt[] 中的一个字符
                    }
                
                }
                length = strlen(arrayt);

                if (length == 0)
                {
                    if (tempsize < ressize)
                    {
                        ressize = tempsize;
                        vector<char>::iterator it;
                        string tempres;
                        for (it = q.begin(); it != q.end(); it++)
                        {
                            tempres.push_back(*it);
                        }
                        res = tempres;
                    }
                    break; 
                }

            }

            
        }
        return res;
    }
};
```
双指针第一版本：  
超时，265/266 个测试用例  
具体思想：
窗口中是覆盖 t 的最小字符串，使用 map arr 来记录 t 中各个字符的个数，并使用 map arr1 来记录当前窗口中各个字符的个数；  
当 arr1 中的各个字符个数能够覆盖 arr 中所有字符的时候，说明此时窗口中已有目标子字符串，则对比当前字符串和最终 res 字符串的长度，如果比 res 长度小则赋值，并前进左窗口；  
否则，正常前进右窗口，继续搜查子字符串  
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> arr;
        for (char c : t)
        {
            map<char, int>::iterator it;
            it = arr.find(c);
            if (it != arr.end() || arr[c] == 0)
            {
                ++arr[c]; 
            }
            else 
            {
                arr.insert(pair<char, int>(c, 1));
            }
        }
        int i = 0; // 作为前指针

        map<char, int> arr1;
        string res;
        string tempres;
        for (int j = 0; j <= s.size(); j++)
        {
            int tag = 0;
            for (char c : t)
            {
                map<char, int>::iterator it;
                it = arr1.find(c);
                if (it == arr1.end() || arr1[c] < arr[c])
                {
                    tag = 1;
                    break;
                }
            }

            if (tag == 0)
            {

                map<char, int>::iterator it;
                it = arr1.find(s[i]);
                if (it != arr1.end())
                {
                    --arr1[s[i]];
                }
                
                if (res == "")
                    res = tempres;
                else
                {
                    if (tempres.size() < res.size())
                        res = tempres;
                }

                for (auto x = begin(tempres); x != end(tempres); x++)
                {
                    if (*x == s[i])
                    {
                        tempres.erase(x);
                        break;
                    }
                }
                ++i;
                --j;
            }
            else
            {
                tempres.push_back(s[j]);
                map<char, int>::iterator it;
                it = arr1.find(s[j]);
                if (it != arr1.end() || arr1[s[j]] == 0)
                {
                    ++arr1[s[j]]; 
                }
                else 
                {
                    arr1.insert(pair<char, int>(s[j], 1));
                }
            }



        }
        return res;

    }
};
```

