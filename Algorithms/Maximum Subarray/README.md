# [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/#/description)
###### No:`53`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number[]} nums
 * @return {number}
 */
 // https://discuss.leetcode.com/topic/6413/dp-solution-some-thoughts
var maxSubArray = function(nums) {
    var max = nums[0];
    var dp = {};
    dp[0] = nums[0];
    
    for (var i = 1; i < nums.length; i++) {
        dp[i] =  dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        max = Math.max(max, dp[i]);
    }
    
    return max;
};
```
