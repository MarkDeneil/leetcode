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
