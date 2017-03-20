# [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)
###### No:`453`
###### Difficulty:`Easy`
## JavaScript

### Solution:
Increasing n-i elements by 1 is same as decrease 1 elements by 1.
Get the minimum number and calculate the sum of other elements minus minimum.

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    var min = Math.min.apply(null, nums)

    return nums.reduce((p, c) => p + c - min, 0);
};
```
