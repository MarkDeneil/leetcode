本题主要思路有三点：  
双维度贪心，要首先确定好一个维度。  
可以按照身高从大向小排序，然后再按照第二个维度 k 来一个个插入。  
排好序后，优先按照身高高的人来插入，这样后面插入的元素也不会影响前面的  
可以使用 list 来插入  

```cpp
bool cmp(vector<int> & v1, vector<int> & v2) {
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] > v2[0];
    }
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        // 排好序后，优先按照身高高的人来插入，这样后面插入的元素也不会影响前面的
        list<vector<int>> lst;
        for (auto x : people) {
            int index = x[1];
            list<vector<int>>::iterator a = lst.begin();
            for (int i = 0; i < index; ++i) // list 的迭代器不是随机访问迭代器，不能使用 a += index;
                ++a;
            lst.insert(a, x);
        }
        vector<vector<int>> res(lst.begin(), lst.end());
        return res;

    }
};
```
