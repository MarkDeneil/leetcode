排序 + 双指针
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 排序 + 双指针
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0, size1 = nums1.size(), size2 = nums2.size();
        vector<int> tempres;
        while (p1 != size1 && p2 != size2)
        {
            if (nums1[p1] < nums2[p2])
                ++p1;
            else if (nums1[p1] > nums2[p2])
                ++p2;
            else
            {
                tempres.push_back(nums1[p1]);
                ++p1;
                ++p2;
            }
        }
        set<int> tempres1(tempres.begin(), tempres.end());
        vector<int> res(tempres1.begin(), tempres1.end());
        return res;
    }
};
```
