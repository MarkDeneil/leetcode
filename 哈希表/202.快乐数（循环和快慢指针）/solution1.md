```cpp
class Solution {
public:

    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        // 循环 && 快慢指针
        // 快指针一次走两步，慢指针一次走一步，如果有循环最终会在环内相遇
        // 如果相遇且相遇结点不是 1 ，则无限循环
        // 本题不用求相遇结点的位置，结点相遇位置可以这样求：从相遇节点出发，与从初始结点出发，走的步数一样
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        
        return slow == 1;

    }
};
```
