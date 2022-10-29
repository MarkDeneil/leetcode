对于每个滑动窗口，我们可以使用 O(k)O(k) 的时间遍历其中的每一个元素，找出其中的最大值。对于长度为 nn 的数组 numsnums 而言，窗口的数量为 n−k+1n−k+1，因此该算法的时间复杂度为 O((n−k+1)k)=O(nk)O((n−k+1)k)=O(nk)，会超出时间限制;  
写法如下，超出时间限制：  
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < k; ++i)
            dq.push_back(nums[i]);
        int max = -10001;
        for (auto x : dq) {
            if (x > max)
                max = x;
        }
        res.push_back(max);
        int iter = nums.size() - k; // 还需迭代的次数

        int index = k; // 需要新加入队列元素的下标
        for (; iter != 0; --iter) {
            int tempf = dq.front();
            if (tempf != max) { // 说明此次移除队列头元素后，最大值仍然在队列中，只需比较新进队尾的元素与最大值的大小
                dq.pop_front();
                dq.push_back(nums[index]);
                ++index;
                if (dq.back() > max)
                    max = dq.back();
            } else { // 可能需要重新计算队列中的最大值
                dq.pop_front();
                dq.push_back(nums[index]);
                ++index;
                if (dq.back() > max) // 此时仍然不需要重新计算最大值，因为原队列中的元素都比 max 小，新加入的元素比 max 大
                    max = dq.back();
                else { //需要重新计算队列中的最大值
                    max = -10001;
                    for (auto x : dq) {
                        if (x > max)    
                            max = x;
                    }
                }
            }
            res.push_back(max);
        }
        return res;
    }
};
```
