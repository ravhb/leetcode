# [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/#/description)
###### No:`496`
###### Difficulty:`Easy`



```js
/**
 * @param {number[]} findNums
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElement = function(findNums, nums) {
    var map = {};
    var stack = [];
    nums.forEach(function(num) {
        while(stack.length > 0 && stack[stack.length - 1] < num) {
            map[stack.pop()] = num;
        }
        stack.push(num);
    });
    
    return findNums.map(function(num) {
        return map[num] || -1;
    });
};
```
