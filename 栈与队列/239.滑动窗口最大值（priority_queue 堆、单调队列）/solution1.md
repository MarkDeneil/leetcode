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
因为本题目中求滑动窗口的最大值，因此我们希望有一个队列能够一直维持其最大值在其队头，直接返回`front()`就可以得到最大值；但是又不能使用`priority_queue`，因为每次右移一次队列，都要从队列中删除一个值；而`priority_queue`是基于 max_heap 的，max_heap 只能每次删除其最大值；  
因此，我们维护一个单调队列：队列中的元素是非严格单调递减的；  
重点：每次向其中加入元素到队尾时，把队尾中小于该待加入元素的值都从队尾去掉，然后再加入该元素。  
当滑动窗口向右移动时，要从单调队列中删除滑动窗口最左端的元素，只要这个最左端的元素不是当前滑动窗口的最大值，就不必删除。  
可能会提出一个问题：当加入元素到队列时，我们删除了一些元素，有没有可能这些被删除的元素，后来有可能成为滑动窗口中的最大值？  
例如，当前队列为`[98,99]`，然后来了一个`100`,又来了一个`3`  
加入`100`时，要把`98,99`都删除，再加入`100`;然后又加入了`3`，此时队列变为`[100,3]`  
如果之后`100`从队列移出去，那么本来没删除`98,99`两个数时，滑动窗口最大值应该为`99`，但现在已经把`99`删除了，因此当前的滑动窗口最大值为`3`！  
其实上述观点是有误的，因为删除`100`时，是因为`100`是滑动窗口最左端的值，当滑动窗口右移后，我们就要从单调队列中删除`100`  
但是，因为`98,99`两个数在还未加入`100`之前就已经在单调队列中了，那么，`98,99`两个数在滑动窗口中的位置还要在`100`这个数的左边！因此删除`100`时，`98,99`两个数早已不在滑动窗口的范围之内了，因此删除`100`后的滑动窗口最大值也不可能从这两个数中选。  
在滑动窗口右移，删除元素时，也只需要考虑当滑动窗口最左侧的值等于单调队列中最大值，才从单调队列中删除最大值；当滑动窗口最左侧的值不是当前单调队列最大值 x 时，我们在向单调队列加入值 x 时就已经将这些滑动窗口最左侧的值从单调队列中删除了，现在滑动窗口右移时自然就不用管这些不大于 x 的滑动窗口最左侧的值了。  
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
