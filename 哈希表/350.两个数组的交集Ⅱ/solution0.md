方法一：建立两个 map
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 两个 map 
        map<int, int> map1;
        map<int, int> map2;
        for (auto & x : nums1)
        {
            pair<map<int, int>::iterator, bool> p = map1.insert(make_pair(x, 1));
            if (p.second == false)
            {
                ++((*(p.first)).second);
            }
        }

        for (auto & x : nums2)
        {
            pair<map<int, int>::iterator, bool> p = map2.insert(make_pair(x, 1));
            if (p.second == false)
            {
                ++((*(p.first)).second);
            }
        }

        vector<int> res;
        for (auto & x : map1)
        {
            map<int, int>::iterator it = map2.find(x.first);
            if (it != map2.end() )
            {
                int count = x.second >= it -> second ? it -> second : x.second;
                for (int i = 0; i < count; ++i)
                {
                    res.push_back(x.first);
                }
            }
        }
        return res;
    }
};
```
方法二：排序 + 双指针  
与 349.两个数组的交集 方法相同，只不过不需要使得最后的结果不重复，所以最后不需要用 set 转换。  
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 排序 + 双指针
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0, size1 = nums1.size(), size2 = nums2.size();
        vector<int> res;
        while (p1 != size1 && p2 != size2)
        {
            if (nums1[p1] < nums2[p2])
                ++p1;
            else if (nums1[p1] > nums2[p2])
                ++p2;
            else
            {
                res.push_back(nums1[p1]);
                ++p1;
                ++p2;
            }
        }
        return res;
    }
};
```
