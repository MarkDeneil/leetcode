难点在于：怎么想到用 哈希法？
**什么时候使用哈希法：当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法。**  
两数之和，在遇到一个新的数的时候，会在数组里查找 target - 新的数 有没有出现过 --> 哈希法。  
使用一个 map 来存储已经访问过的元素，当遇到新元素 num 时，查看该 map 中是否有 target - num  
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int temp = target - nums[i];
            if (m.find(temp) != m.end())
                {
                    res.push_back(m[temp]);
                    res.push_back(i);
                    return res;
                }
            else
            {
                m.insert(make_pair(nums[i], i));
            }
        }
        return res;
    }
};
```
