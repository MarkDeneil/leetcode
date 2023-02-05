思路：  
遇到strNum\[i - 1] > strNum\[i]的情况，让strNum\[i - 1]--，然后strNum[i]给为9，可以保证这两位变成最大单调递增整数。  
```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 思路：遇到strNum[i - 1] > strNum[i]的情况，让strNum[i - 1]--，然后strNum[i]给为9，可以保证这两位变成最大单调递增整数。
        // 例如：98 变为 89
        // 从右往左遍历，例如 332：右二比右一大，因此变为 329；右三比右二大，因此变为 299
        string str = to_string(n);
        int ssize = str.size();
        int index = -1; // 记录从右往左最后一个变 9 的下标,如 7428，右一大于右二，因此右一不变，右二小于右三，因此右二变 9，右三减一，且右二之后的数字全部变九，index 就是用来记录右二的下标
        string res;
        for (int i = ssize - 1; i >= 1; --i) {
            if (str[i] - '0' < str[i-1] - '0') { // 会自动处理好某位为 '0' 的情况
                str[i] = '9';
                str[i-1] = char(str[i-1] - 1);
                index = i;
            }
        }
        if (index != -1) {
            for (int i = index; i < ssize; ++i) {
                str[i] = '9';
            }
        }
        return stoi(str.c_str());
    }
};
```
