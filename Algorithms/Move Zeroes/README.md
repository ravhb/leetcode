# [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
###### No:`283`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    var sum = 0;
    for(var i = nums.length - 1; i >=0; i--) {
        if(nums[i] === 0) {
            nums.splice(i,1);
            sum++;
        }
    }
    [].push.apply(nums, new Array(sum).fill(0))
};
```
