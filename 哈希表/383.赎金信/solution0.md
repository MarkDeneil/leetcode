1. 使用 map，其中 map 的遍历操作（使用迭代器或auto都可）和 find 操作（若找到则返回指向的元素，未找到返回尾后迭代器）要注意。  
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m1, m2; // m1 记录 ransomNote 中出现的字符，m2 记录 magazine 中出现的字符
        for (char x : ransomNote)
        {
            pair<map<char, int>::iterator, bool> res1 = m1.insert(make_pair(x, 1));
            if (res1.second == false)
                ++((*(res1.first)).second);
        }

        for (char x : magazine)
        {
            pair<map<char, int>::iterator, bool> res1 = m2.insert(make_pair(x, 1));
            if (res1.second == false)
                ++((*(res1.first)).second);
        }

        map<char, int>::iterator it;
        for (it = m1.begin(); it != m1.end(); ++it)
        {
            map<char, int>::iterator p;
            if ((p = m2.find((*it).first)) == m2.end())
                return false;
            else
                if ((*it).second > (*p).second)
                    return false;
        }
        return true;
        
    }
};
```
2. 使用一个数组代替 map，索引 0-25 代表 a-z，用此方法用时更短
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 定义一个数组作为 map（0-25 索引映射到 a-z）
        array<int, 26> arr;
        for (int i = 0 ; i < 26; ++i)
            arr[i] = 0;
        for (auto x : ransomNote)
        {
            ++arr[int(x) - 97];
        }

        for (auto x : magazine)
        {
            --arr[(int)x - 97];
        }

        for (auto x : arr)
        {
            if (x > 0)
                return false;
        }
        return true;
    }
};
```
