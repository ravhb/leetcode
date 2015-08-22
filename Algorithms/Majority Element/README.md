#[Majority Element](https://leetcode.com/problems/majority-element/)
######No:`169`
######Difficulty:`Easy`
##JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    var count = 1;
    var item = nums[0];
    for(var i = 1; i < nums.length; i++) {
        if(count === 0) {
            count = 1;
            item = nums[i];
        } else {
            if(nums[i] == item) {
                count++;
            } else {
                count--;
            }
        }
    }
    return item;
};
```
