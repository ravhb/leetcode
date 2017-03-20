# [Summary Ranges](https://leetcode.com/problems/summary-ranges/)
###### No:`228`
###### Difficulty:`Easy`
## JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    if(nums.length === 0) {
        return nums;
    }

    var ret = [];
    var start = 0;

    for(var i = 1; i < nums.length; i++) {
        if(nums[i] - nums[i-1] != 1) {
            ret.push(nums.slice(start, i));
            start = i;
        }
    }
    ret.push(nums.slice(start));

    ret = ret.map(function(item) {
        if(item.length > 1) {
            return item[0] + '->' + item[item.length - 1];
        } else {
            return item[0] + '';
        }
    });

    return ret;
};
```
