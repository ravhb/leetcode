# [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/#/description)
###### No:`532`
###### Difficulty:`Easy`
## JavaScript


```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
  if (k < 0 || nums.length === 0) return 0;
  var itemCountMap = {};
  var count = 0;

  nums.forEach((item, index) => {
    itemCountMap[item] === undefined ? itemCountMap[item] = 1 : itemCountMap[item]++;
  });

  if (k === 0) {
    for (var key in itemCountMap) {
      if (itemCountMap[key] >= 2) {
        count++;
      }
    }
  } else {
    for (var key in itemCountMap) {
      if (itemCountMap[parseInt(key)+ k] !== undefined) {
        count++;
      }
    }
  }

  return count;
};

```
