# [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/#/description)
###### No:`453`
###### Difficulty:`Easy`



```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    var min = Math.min.apply(null, nums)
    
    return nums.reduce((p, c) => p + c - min, 0);
};
```
