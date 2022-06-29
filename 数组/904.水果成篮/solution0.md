暴力解法，71/91 个通过测试用例，超出时间限制
```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            int type = 0;
            int firsttype = -1;
            int secondtype = -1;
            int j = i;
            int tempres = 0;
            while (type != 3 && j != size)
            {
                if (type == 0)
                {
                    firsttype = fruits[j];
                    ++type;
                    ++tempres;
                }
                else if (type == 1)
                {
                    if (fruits[j] == firsttype)
                    {
                        ++tempres;
                    }
                    else
                    {
                        secondtype = fruits[j];
                        ++type;
                        ++tempres;
                    }
                }
                else
                {
                    if (fruits[j] == firsttype || fruits[j] == secondtype)
                    {
                        ++tempres;
                    }
                    else
                    {
                        ++type;
                    }
                }
                ++j;
            }
            res = tempres > res ? tempres : res;
        }
        return res;
    }
};
```
滑动窗口，使用滑动窗口方法时，要时刻确定以下三点：
- 窗口内是什么？
- 如何移动窗口的起始位置？
- 如何移动窗口的结束位置？  
显然，本题中，窗口里应该装的是两种果树；  
窗口的后指针：普通行进，直到到达最后
窗口的前指针：当后指针遇到第三种果树时，就应该移动前指针了。将前指针移动到最新的一种果树的第一个位置，如 111222333 ，当后指针来到 3 时，前指针就应该移动到第一个 2 的位置。为此，需要记录该位置，且移动了前指针后，当前窗口内果树的数量应该对应的减少。
```cpp
class Solution
{
public:
   int totalFruit(vector<int> &fruits)
   {
      int size = fruits.size();
      int i = 0; // i 做左窗口
      int maxfruit = 0;
      int firsttype = -1;
      int secondtype = -1;
      int type = 0; // 记录当前类型数量

      int tempfruit = 0;             // 记录篮子中当前水果量
      int pos = -1;                  // 记录左窗口每次移动到的位置（即当前窗口中最后一种水果最早的位置的前一个位置）
      for (int j = 0; j < size; j++) // j 做右窗口
      {

         if (type == 0)
         {
            firsttype = fruits[j];
            ++tempfruit;
            ++type;
         }
         else if (type == 1)
         {
            if (fruits[j] != firsttype)
            {
               secondtype = fruits[j];
               ++tempfruit;
               ++type;
               pos = j; // 111222333 这种情况下第一个 2 的位置需要记录为 pos
            }
            else
            {
               ++tempfruit;
            }
         }
         else
         {
            if (fruits[j] == firsttype || fruits[j] == secondtype)
            {
               if (fruits[j] != fruits[j - 1])
                  pos = j;
               ++tempfruit;
            }
            else
            {

               if (fruits[pos - 1] == firsttype)
                  firsttype = fruits[j];
               else
                  secondtype = fruits[j];
               tempfruit -= pos - i; // 移动前窗口后，当前水果数也相应减少
               i = pos;
               ++tempfruit; // 把本次的水果数加入新篮子
               pos = j; // 更新新的 pos 
            }
         }
         maxfruit = (tempfruit > maxfruit) ? tempfruit : maxfruit;
      }
      return maxfruit;
   }
};
```

