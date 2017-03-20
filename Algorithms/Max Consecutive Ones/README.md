# [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/#/description)
###### No:`485`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    var max = 0;
    var length = 0;
    nums.forEach(function(num) {
        if (num === 1)  length++;
        if (num === 0) {
            if (length > max) max = length;
            length = 0;
        }
    });
    if (length > max) max = length;
    return max;
};
```
