# [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/#/description)
###### No:`448`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    var map = {};
    var ret = [];
    
    nums.forEach(function(num) {
        map[num] = true;
    });
    
    for (var i = 1; i <= nums.length; i++) {
        if (map[i] === undefined) {
            ret.push(i);
        }
    }
    
    return ret;
};
```
