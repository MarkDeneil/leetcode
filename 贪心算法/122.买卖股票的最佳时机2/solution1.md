解法1.可以按照 376.摆动序列 的方法类似来处理，这样可以得到每一段的区间  
![image](https://user-images.githubusercontent.com/83362131/215324677-31b90dfe-e765-4faa-b190-47e85c52c06b.png)  
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 与 376.摆动序列 类似，比这题简单一些
        // 思路：本方法按照判断区间的方式来写，设置 prediff 和 curdiff，基本思想是: prediff > 0 && curdiff < 0 ，如果有股票就卖出并计算收益； prediff < 0 && curdiff > 0 时，如果无股票就买入，并计算收益起点
        // 并且要考虑三种情况：1.两端 2.上下坡中有平坡 3.单调中有平坡
        int res = 0;
        if (prices.size() == 1) 
            return 0;
        int prediff = 0;
        int curdiff = 0;

        bool has = false; // 标记有无股票
        int startmoney = 0; // 标记收益起点

        if (prices[1] - prices[0] > 0) { // 1.两端： 第一个结点：curdiff <= 0 不买，curdiff > 0 买，然后从第二个结点开始遍历；最后一个结点：如果有就卖出
            if (has == false) {
                has = true;
                startmoney = prices[0];
            }
        }

        for (int i = 1; i < prices.size() - 1; ++i) {
            prediff = prices[i] - prices[i - 1];
            curdiff = prices[i + 1] - prices[i];
            if (prediff >= 0 && curdiff < 0) { // 2.上下坡中有平坡：因此在两个判断式的前半部分都加上了 等于0 的条件；3.单调中有平坡：此时发现单调中哦有平坡可以正确计算收益了
                if (has == true) { // 卖了算收益
                    res += prices[i] - startmoney;
                    has = false;
                    startmoney = 0;
                }
            }

            if (prediff <= 0 && curdiff > 0) {
                if (has == false) { // 买了，计算起点
                    has = true;
                    startmoney = prices[i];
                }
            }
        }

        // 最后一天，有就卖
        if (has == true) {
            res += prices[prices.size() - 1] - startmoney;
        }
        return res;
    }
};
```
解法2.不需要计算区间，只收集正利润  
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 不需要计算区间，只需要收集正利润
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += (prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0);
        }
        return res;
    }
};
```
