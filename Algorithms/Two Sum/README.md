# [Two Sum](https://leetcode.com/problems/two-sum/)
###### No:`1`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var ret = [];
    for(var i = 0; i < nums.length; i++) {
        for(var j = i + 1; j < nums.length; j++) {
            if(nums[i] +  nums[j] === target) {
                ret.push(i);
                ret.push(j);
            }
        }
    }
    return ret;
};
```
