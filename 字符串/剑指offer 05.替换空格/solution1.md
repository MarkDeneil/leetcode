双指针法  
首先扩充数组到每个空格替换成"%20"之后的大小；然后从后向前替换空格，也就是双指针法；  
**其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。**  
这么做有两个好处：  
- 不用申请新数组。  
- 从后向前填充元素，避免了从前先后填充元素要来的 每次添加元素都要将添加元素之后的所有元素向后移动。  
![e6c9d24ely1go6qmevhgpg20du09m4qp](https://user-images.githubusercontent.com/83362131/187460882-2cd7303d-0e62-4d95-9c50-18b2536ea433.gif)

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
                ++count;
        }
        int j = s.size() - 1;
        s.resize(s.size() + count * 2);
        int i = s.size() - 1;
        for (; j < i; --j, --i)
        {
            if (s[j] != ' ')
            {
                s[i] = s[j];
            }
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};
```
