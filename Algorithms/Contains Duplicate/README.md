#[Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
######No:`217`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    for(var i = 0; i < nums.length; i++) {
        for(var j = i + 1 ; j < nums.length; j++) {
            if(nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
};
```
