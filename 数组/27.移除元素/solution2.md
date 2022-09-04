双指针法，可以保证移除元素后数组的剩余元素的顺序
定义快慢指针：
- 快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
- 慢指针：指向更新 新数组下标的位置  
一定要理解快慢指针的定义。  
对快慢指针的新理解：
其实就是利用快指针来找不含有目标元素的数据，在赋值给慢指针，这个过程相当于用慢指针在原来的数组中一点点构建一个新的数组,构造该数组用到的元素就是快指针一步步前进找到的在目标数组中的元素。  
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastpointer = 0;
        int slowpointer = 0;
        for (fastpointer = 0; fastpointer < nums.size(); fastpointer++)
        {
            if(nums[fastpointer] != val)
            {
                nums[slowpointer] = nums[fastpointer];
                slowpointer++;
            }
        }
        return slowpointer;
    }
};
```
