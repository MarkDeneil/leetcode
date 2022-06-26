暴力解法，71/91 个通过测试用例，超出时间限制
```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            int type = 0;
            int firsttype = -1;
            int secondtype = -1;
            int j = i;
            int tempres = 0;
            while (type != 3 && j != size)
            {
                if (type == 0)
                {
                    firsttype = fruits[j];
                    ++type;
                    ++tempres;
                }
                else if (type == 1)
                {
                    if (fruits[j] == firsttype)
                    {
                        ++tempres;
                    }
                    else
                    {
                        secondtype = fruits[j];
                        ++type;
                        ++tempres;
                    }
                }
                else
                {
                    if (fruits[j] == firsttype || fruits[j] == secondtype)
                    {
                        ++tempres;
                    }
                    else
                    {
                        ++type;
                    }
                }
                ++j;
            }
            res = tempres > res ? tempres : res;
        }
        return res;
    }
};
```
