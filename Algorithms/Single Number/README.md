# [Single Number](https://leetcode.com/problems/single-number/)
###### No:`136`
###### Difficulty:`Medium`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    return nums.reduce(function(prev, cur) {
        return prev ^ cur;
    });
};
```

#### Description:
Any number that XOR itselt will be 0;

