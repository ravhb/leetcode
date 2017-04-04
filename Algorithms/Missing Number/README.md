# [Missing Number](https://leetcode.com/problems/missing-number/)
###### No:`268`
###### Difficulty:`Medium`

#### Solution 1
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    return (0 + nums.length) * (nums.length + 1) / 2 - nums.reduce((p, c) => p + c, 0);
};
```

#### Solution 2
Any number XOR itself will be 0.
e.g.[0,1,3]
ret = （0 ^ 1 ^ 3） ^ (0 ^ 1 ^ 2 ^ 3) // will get 2
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    return nums.reduce((p, c, i) => p ^ c ^ i, 0) ^ nums.length;
};
```
