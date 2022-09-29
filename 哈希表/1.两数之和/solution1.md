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
