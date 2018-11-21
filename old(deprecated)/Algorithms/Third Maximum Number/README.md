# [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/#/description)
###### No:`414`
###### Difficulty:`Easy`



```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var getMax = function(nums) {
  return Math.max.apply(null, nums);
};

var removeItem = function(nums, item) {
  return nums.filter((value) => value !== item);
};

var thirdMax = function(nums) {
  var first = getMax(nums);
  nums = removeItem(nums, first);
  var second = getMax(nums);
  nums = removeItem(nums, second);

  if (nums.length === 0) return first;
  return getMax(nums);

};

```
