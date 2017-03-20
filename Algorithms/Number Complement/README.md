# [Number Complement](https://leetcode.com/problems/number-complement/#/description)
###### No:`476`
###### Difficulty:`Easy`



```js
/**
 * @param {number} num
 * @return {number}

这道题给了我们一个数，让我们求补数。通过分析题目汇总的例子，我们知道需要做的就是每个位翻转一下就行了，但是翻转的起始位置上从最高位的1开始的，前面的0是不能被翻转的，所以我们从高往低遍历，如果遇到第一个1了后，我们的flag就赋值为true，然后就可以进行翻转了，翻转的方法就是对应位异或一个1即可，参见代码如下：

 

解法一：

复制代码
class Solution {
public:
    int findComplement(int num) {
        bool start = false;
        for (int i = 31; i >= 0; --i) {
            if (num & (1 << i)) start = true;
            if (start) num ^= (1 << i);
        }
        return num;
    }
};
复制代码
 

由于位操作里面的取反符号～本身就可以翻转位，但是如果直接对num取反的话就是每一位都翻转了，而最高位1之前的0是不能翻转的，所以我们只要用一个mask来标记最高位1前面的所有0的位置，然后对mask取反后，与上对num取反的结果即可，参见代码如下：

 

解法二：

复制代码
class Solution {
public:
    int findComplement(int num) {
        int mask = INT_MAX;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};
复制代码
 

再来看一种迭代的写法，一行搞定碉堡了，思路就是每次都右移一位，并根据最低位的值先进行翻转，如果当前值小于等于1了，就不用再调用递归函数了，参见代码如下：

 

解法三：

class Solution {
public:
    int findComplement(int num) {
        return (1 - num % 2) + 2 * (num <= 1 ? 0 : findComplement(num / 2));
    }
};

 */
 
var findComplement = function(num) {
    var mask = ~0;
    while (mask & num) mask <<= 1;
    return ~mask & ~num;
};
```
