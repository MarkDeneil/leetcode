01 背包的特点是所有的元素只能用一次，求特定容量下可以放得下的物品的最大价值。  
推导过程：  
![IMG_0380](https://user-images.githubusercontent.com/83362131/220664033-0f0729cd-7bb7-4ade-a4e5-304b6a562180.PNG)
01 背包的二维 dp 数组改为滚动数组的思想就是**压缩 dp 数组，将上一层 dp 数组的元素拷贝到当前 dp 数组中**。
01 背包的二维 dp 数组中，两层 for 循环的顺序可以颠倒，即**先遍历物品，再遍历背包容量，或先遍历背包容量，再遍历物品**，都可以。  
01 背包的滚动数组推导：（需要注意倒序遍历容量 j，且内层循环中`j >= weight[i]`这一条件，因为在`j < weight[i]`时，滚动数组的第 i 层直接就是第 i-1 层的内容，因此不需要变动）  
![IMG_0381(20230222-231807)](https://user-images.githubusercontent.com/83362131/220666934-a32a1a4b-37f3-4cd2-b074-2a229e3a7ea7.PNG)
![IMG_0382(20230222-231831)](https://user-images.githubusercontent.com/83362131/220666948-edf732bf-5c19-43aa-b981-87485b9ae1f7.PNG)  
01 背包的滚动数组中，因为需要倒序遍历容量 j，因此两层 for 循环不能颠倒，即**01 背包滚动数组必须先遍历元素，再遍历背包容量**；如果一旦颠倒，则求出的 dp\[j] 代表当前容量下能存放的一个最大价值物品的价值  

![IMG_0383(20230222-232529)](https://user-images.githubusercontent.com/83362131/220669470-b8fac9a8-a89b-4621-bdcb-88a131473c4f.PNG)
![IMG_0384(20230222-232547)](https://user-images.githubusercontent.com/83362131/220669476-ab749e72-e5a1-46a3-a9be-1f5a698c4c52.PNG)
