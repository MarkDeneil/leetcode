重定义 priority_queue 的比较操作：  
1. 使用标准库里的函数对象来重定义 less<int>  
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        for (auto x : nums) {
            if (m.find(x) == m.end()) 
                m.insert(pair<int, int>(x, 1));
            else 
                ++m[x];
        }
        multimap<int, int> multim;
        for (auto x : m) {
            multim.insert(make_pair(x.second, x.first));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (auto x : multim) 
            pq.push(x);
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```
2. 使用 lambda 表达式  
```cpp

// bool shorter(const pair<int, int> &p1, const pair<int, int> &p2) {
//     return p1.second < p2.second;
// }


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        for (auto x : nums) {
            if (m.find(x) == m.end()) 
                m.insert(pair<int, int>(x, 1));
            else 
                ++m[x];
        }
        
        // 构造 lambda 表达式
        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) { return p1.second < p2.second; };

        // priority_queue<m.begin(), m.end(), decltype(shorter)> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto x : m) 
            pq.push(x);
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```
3. 自定义函数对象类（结构体）来重定义 priority_queue 的比较操作  
```cpp

// bool shorter(const pair<int, int> &p1, const pair<int, int> &p2) {
//     return p1.second < p2.second;
// }
struct shorter{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        for (auto x : nums) {
            if (m.find(x) == m.end()) 
                m.insert(pair<int, int>(x, 1));
            else 
                ++m[x];
        }
        

        // priority_queue<m.begin(), m.end(), decltype(shorter)> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, shorter> pq;
        for (auto x : m) 
            pq.push(x);
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```
4. 函数指针类型  
```cpp
bool shorter(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}
// struct shorter{
//     bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
//         return p1.second < p2.second;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        for (auto x : nums) {
            if (m.find(x) == m.end()) 
                m.insert(pair<int, int>(x, 1));
            else 
                ++m[x];
        }
        

        // priority_queue<m.begin(), m.end(), decltype(shorter)> pq;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(shorter)> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, bool (*)(const pair<int, int> &p1, const pair<int, int> &p2)> pq(shorter);
        
        for (auto x : m) 
            pq.push(x);
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```
5. 函数指针类型2
```cpp
bool shorter(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}
// struct shorter{
//     bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
//         return p1.second < p2.second;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        for (auto x : nums) {
            if (m.find(x) == m.end()) 
                m.insert(pair<int, int>(x, 1));
            else 
                ++m[x];
        }
        

        // priority_queue<m.begin(), m.end(), decltype(shorter)> pq;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(shorter)> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(shorter)*> pq(shorter);

        for (auto x : m) 
            pq.push(x);
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```
