使用 bind 与 标准库定义的函数对象结合 作为 find_if 的谓词参数（find_if 只接受一元谓词）  
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for (auto x : nums1)
        {
            if (find_if(nums2.begin(), nums2.end(), bind(equal_to<int>(), std::placeholders::_1, x)) != nums2.end())
            {
                s.insert(x);
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};

使用 lambda 表达式  
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for (auto x : nums1)
        {
            if (find_if(nums2.begin(), nums2.end(), [&](int i){return x == i;}) != nums2.end())
            {
                s.insert(x);
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};
```
使用自定义函数对象  
```cpp
class notequal{
private:
    int x;
public:
    notequal(int i):x(i) {}
    bool operator()(int & i) const
    {
        return i == x;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for (auto x : nums1)
        {
            if ( find_if(nums2.begin(), nums2.end(), notequal(x)) != nums2.end())
            {
                s.insert(x);
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};
```

