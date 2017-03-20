# [Missing Number](https://leetcode.com/problems/missing-number/)
###### No:`268`
###### Difficulty:`Medium`


```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    return (0 + nums.length) * (nums.length + 1) / 2 - nums.reduce((p, c) => p + c, 0);
};
```
