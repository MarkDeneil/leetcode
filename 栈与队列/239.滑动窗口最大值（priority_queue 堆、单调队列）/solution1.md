使用优先级队列（堆） priority_queue<Type>  
思路：可以维护一个大根堆，作为已经排好序的滑动窗口。但是当滑动窗口向右移动时，要移除滑动窗口最左边的值，因此我们要在维护的 priority_queue 大根堆中移除该元素。但 priority_queue 中只能使用 pop() 弹出堆顶元素，因此如何从大根堆中移除滑动窗口中最左侧的元素？  
可以将一个 pair 放入大根堆中，first 元素是滑动窗口中元素的值，second 元素是滑动窗口中元素的下标。**当大根堆堆顶元素的下标小于滑动窗口最左侧的下标时，说明该堆顶元素已经被移出滑动窗口**，因此使用 pop() 将该元素弹出大根堆。  
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (int i = 0; i < k; ++i)
            pq.push(make_pair(nums[i], i));
        int iter = nums.size() - k;
        res.push_back(pq.top().first);
        for (int i = k; i < nums.size(); ++i) { // i 代表滑动窗口最右边的窗口，一直遍历到最后一个元素
            pq.push(make_pair(nums[i], i));
            while (pq.top().second < i - k + 1) { // 在维护的大根堆中移除滑动窗口最左侧的值
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        return res;
    }
};
```

使用单调队列（队列中维护单调元素）  
设计单调队列的时候，pop，和push操作要保持如下规则：  
pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作  
push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止  
![239 滑动窗口最大值-2](https://user-images.githubusercontent.com/83362131/198886917-9f79c6da-a462-42c1-841c-741a29f0a561.gif)  
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q; // 单调队列，维护一个单调递减的队列作为滑动窗口，单调队列里并不保存所有滑动窗口中的值
        for (int i = 0; i < k; ++i) { // 构造初始滑动窗口
            if (q.empty()) 
                q.push_back(nums[i]);
            else {
                while (!q.empty() && q.back() < nums[i]) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
        }
        res.push_back(q.front());
        for (int i = k; i < nums.size(); ++i) { // 滑动窗口向右滑动，i 代表右窗口
            // 移除滑动窗口最左侧元素，注意因为单调队列并不维护所有滑动窗口中的元素，因此不一定会弹出单调队列中的元素
            if (!q.empty() && nums[i - k] == q.front()) // 移除滑动窗口左侧元素
                q.pop_front();
            if (q.empty()) // 向滑动窗口中添加右元素
                q.push_back(nums[i]);
            else {
                while (!q.empty() && q.back() < nums[i]) { // 维护递减队列，当待添加元素大于单调队列的入口元素，则一直 pop 入口元素，值到单调队列为空或
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
            res.push_back(q.front());
        }
        return res;
    }
};
```
