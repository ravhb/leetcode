# [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/#/description)
###### No:`33`
###### Difficulty:`Medium`
## JavaScript


```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function binarySearch(nums, target) {
    var end = nums.length - 1;
    var start = 0;
    var middle = parseInt((start + end) / 2);

    while (end >= start) {
        if (nums[middle] == target) {
            return middle;
        } else if(nums[middle] > target) {
            end = middle - 1;
        } else if(nums[middle] < target) {
            start = middle + 1;
        }
        middle = parseInt((start + end) / 2);
    }
    return -1;
}

var search = function(nums, target) {
    var i = 0;
    while(nums[i] <= nums[i+1]) {
        i++;
    }

    if (nums[0] <= target && target <= nums[i]) {
      return binarySearch(nums.slice(0, i + 1), target);
    } else if (nums[i + 1] <= target && target <= nums[nums.length - 1]){
      var ret = binarySearch(nums.slice(i + 1), target);
      return ret == -1 ? -1 : i + 1 + ret;
    } else {
      return -1;
    }
};

```
