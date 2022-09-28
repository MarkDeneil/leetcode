```cpp
class Solution {
public:
    bool isHappy(int n) {
        // sum 重复出现则代表不是快乐数
        unordered_map<int, int> map1; // 记录出现过的 sum

        int temp = n;
        vector<int> vec; // 存放 n 各个位置的数字
        while (temp)
        {
            vec.push_back(temp % 10);
            temp /= 10;
        }

        int newnum = 0;
        for (auto & x : vec)
        {
            newnum += x * x;
        }
        
        if (newnum == 1) return true;

        map1.insert(make_pair(newnum, 1));

        while (newnum != 1)
        {
            temp = newnum;
            vector<int> vec; // 存放 n 各个位置的数字
            while (temp)
            {
                vec.push_back(temp % 10);
                temp /= 10;
            }

            newnum = 0;
            for (auto & x : vec)
            {
                newnum += x * x;
            }
            
            pair<unordered_map<int, int>::iterator, bool> it = map1.insert(make_pair(newnum, 1));
            if (it.second == false)
                return false;
        }
        return true;

    }
};
```
