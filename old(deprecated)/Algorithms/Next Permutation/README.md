# [Next Permutation](https://leetcode.com/problems/next-permutation/#/description)
###### No:`31`
###### Difficulty:`Medium`
## JavaScript


```js
var nextPermutation = function(nums) {
    if (nums.length <= 1) {
      return;
    }

    var i = nums.length - 2;
    var j = nums.length - 1;
    while (nums[i] >= nums[i + 1] && i > -1) {
      i--;
    }
    if (i >= 0) {
      while (nums[j] <= nums[i]) {
        j--;
      }

      var temp;
      temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }

    var start = i + 1;
    var end = nums.length - 1;

    while (start < end) {
      temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      start++;
      end--;
    }

};
```
