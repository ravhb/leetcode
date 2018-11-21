# [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description)
###### No:`442`
###### Difficulty:`Medium`



```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    var ret = [];
    for (var i = 0; i < nums.length; i++) {
        var index = Math.abs(nums[i]) - 1;
        if (nums[index] < 0) {
            ret.push(Math.abs(nums[i]));
        }
        nums[index] = -Math.abs(nums[index]);
    }
    
    return ret;
};
```
