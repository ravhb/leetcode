# [Rotate Array](https://leetcode.com/problems/rotate-array/)
###### No:`189`
###### Difficulty:`Easy`


```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    for(var i = 0; i < k; i++) {
        nums.unshift(nums.pop());
    }
};
```
