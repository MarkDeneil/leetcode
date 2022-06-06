// 时间复杂度 O(n)
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int tag = 1;
        int index = 0;
        vector<int> res(2,0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target && tag == 1)
            {
                res[0] = i;
                tag = 0;
            }
            if (nums[i] == target)
                res[1] = i;
        }
        if (tag == 1) return vector<int>(2,-1);
        return res;
    }
};
```

// 时间复杂度 O(logn)
// 遍历一遍数组的，考虑两边往中间遍历？
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int tagl = 1;
        int tagr = 1;

        vector<int> res(2,-1);
        while (left <= right)
        {
            if (nums[left] == target && tagl == 1)
            {
                res[0] = left;
                tagl = 0;
            }
            if (nums[right] == target && tagr == 1)
            {
                res[1] = right; 
                tagr = 0;
            }
            if (tagl == 0 && tagr == 0)
                break;
            if (tagl == 1) ++left;
            if (tagr == 1) --right;
        }
        return res;
    }
};
```
