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

