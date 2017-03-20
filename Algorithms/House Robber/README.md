# [House Robber](https://leetcode.com/problems/house-robber/)
###### No:`198`
###### Difficulty:`Easy`


```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if(nums.length === 0) {
        return 0;
    }
    if(nums.length === 1) {
        return nums[0];
    }
    
    var max = {};
    max[0] = nums[0];
    max[1] = Math.max(nums[0], nums[1]);
    for(var i = 2; i < nums.length; i++) {
        max[i] = Math.max(max[i - 2] + nums[i], max[i -1]);
    }
    return max[nums.length - 1];
};
```

```
### How to solve?
```
##### Using DP.
max[0] = nums[0];
max[1] = Math.max(nums[0], nums[1]);
max[n] = Math.max(max[n] + max[n - 2], max[n -1]);
